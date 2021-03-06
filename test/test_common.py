import sys
import os
import pwd
import grp
import time
import platform
import re

def Catch(func, *args, **kwargs):
    try:
        func(*args, **kwargs)
    except:
        return sys.exc_info()[0]
    return None

def Expect(a):
    assert a, "condition does not hold"

def ExpectEq(a, b):
    assert a == b, "{} should be equal {}".format(a, b)

def ExpectNe(a, b):
    assert a != b, "{} should not be equal{}".format(a, b)

def ExpectLe(a, b, descr=""):
    assert a <= b, "{}{} should be less or equal {}".format(descr, a, b)

def ExpectProp(ct, prop, val):
    cur = ct.GetProperty(prop)
    assert cur == val, "{} property {} should be {} not {}".format(ct, prop, val, cur)

def ExpectPropNe(ct, prop, val):
    cur = ct.GetProperty(prop)
    assert cur != val, "{} property {} value {} should be not equal to {}".format(ct, prop, val, cur)

def ExpectPropGe(ct, prop, val):
    cur = int(ct.GetProperty(prop))
    assert cur >= val, "{} property {} should be at least {} not {}".format(ct, prop, val, cur)

def ExpectPropLe(ct, prop, val):
    cur = int(ct.GetProperty(prop))
    assert cur <= val, "{} property {} should be at most {} not {}".format(ct, prop, val, cur)

def ExpectException(func, exc, *args):
    tmp = Catch(func, *args)
    assert tmp == exc, "method {} should throw {} not {}".format(ct, func, exc, tmp)

def MemoryStat(ct, stat):
    for line in ct.GetProperty("memory.stat").splitlines():
        k, v = line.split()
        if k == stat:
            return int(v)
    return None

def ExpectMemoryStatLe(ct, stat, val):
    cur = MemoryStat(ct, stat)
    assert cur is not None, "{} memory.stat:{} not found".format(ct, stat)
    assert cur <= val, "{} memory.stat:{} should be at most {} not {}".format(ct, stat, val, cur)

def UserId(name):
    try:
        return pwd.getpwnam(name).pw_uid
    except KeyError:
        return None

def GroupId(name):
    try:
        return grp.getgrnam(name).gr_gid
    except KeyError:
        return None

alice_uid=UserId("porto-alice")
alice_gid=GroupId("porto-alice")

bob_uid=UserId("porto-bob")
bob_gid=GroupId("porto-bob")

charlie_uid=UserId("porto-charlie")
charlie_gid=GroupId("porto-charlie")

david_uid=UserId("porto-david")
david_gid=GroupId("porto-david")

porto_gid=GroupId("porto")

def AsRoot():
    os.setresgid(0, 0, 0)
    os.setresuid(0, 0, 0)
    os.setgroups([0])

def SwitchUser(username, uid, gid):
    os.initgroups(username, uid)
    os.setresgid(gid, gid, 0)
    os.setresuid(uid, uid, 0)

def AsAlice():
    SwitchUser("porto-alice", alice_uid, alice_gid)

def AsBob():
    SwitchUser("porto-bob", bob_uid, bob_gid)

def AsCharlie():
    SwitchUser("porto-charlie", charlie_uid, charlie_gid)

def AsDavid():
    SwitchUser("porto-david", david_uid, david_gid)

def GetSlavePid():
    pid = int(open("/run/portod.pid").read())
    open("/proc/" + str(pid) + "/status").readline().index("portod-slave")
    return pid

def GetMasterPid():
    pid = int(open("/run/portoloop.pid").read())
    open("/proc/" + str(pid) + "/status").readline().index("portod")
    return pid

def GetState(pid):
    if isinstance(pid, int):
        pid = str(pid)
    ss = open("/proc/" + pid + "/status").readlines()
    for s in ss:
        if s.find("State:") >= 0:
            return s.split()[1]
    return ""

def IsRunning(pid):
    try:
        os.kill(pid, 0)
        state = GetState(pid)
        return state != "Z" and state != "X"
    except:
        return False

def IsZombie(pid):
    return GetState(pid) == "Z"

def KillPid(pid, signal):
    os.kill(pid, signal)
    try:
        ctr = 0
        while ctr < 100:
            time.sleep(0.1)
            os.kill(pid, 0)
            ctr += 1

        raise BaseException("Too long waited for portod to stop")
    except OSError:
        pass

def GetMeminfo(tag):
    meminfo = open("/proc/meminfo", "r").readlines()
    for m in meminfo:
        if m.find(tag) >= 0:
            return int(m.split()[1]) * 1024

def get_kernel_maj_min():
    kver = re.match("([0-9])\.([0-9])", platform.uname()[2]).groups()
    return (int(kver[0]), int(kver[1]))

def DumpObjectState(r, keys):
    for k in keys:
        try:
            value = r.GetProperty(k)
            try:
                value = value.rstrip()
            except:
                pass
        except:
            value = "n/a"

        print "{} : \"{}\"".format(k, value)

    print ""

portosrc = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
portobin = os.getcwd()
portoctl = portobin + "/portoctl"
portod = os.path.abspath(portobin + "/portod")
portotest = portobin + "/portotest"
