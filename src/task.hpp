#pragma once

#include <string>
#include <vector>

#include "util/namespace.hpp"
#include "util/path.hpp"
#include "util/cred.hpp"
#include "util/unix.hpp"
#include "cgroup.hpp"
#include "env.hpp"
#include "filesystem.hpp"

class TContainer;
class TClient;

struct TTaskEnv {
    std::shared_ptr<TContainer> CT;
    TClient *Client;
    TFile PortoInit;
    TMountNamespace Mnt;

    TNamespaceFd IpcFd;
    TNamespaceFd UtsFd;
    TNamespaceFd NetFd;
    TNamespaceFd PidFd;
    TNamespaceFd MntFd;
    TNamespaceFd RootFd;
    TNamespaceFd CwdFd;

    TEnv Env;
    bool TripleFork;
    bool QuadroFork;
    std::vector<TDevice> Devices;
    std::vector<std::string> Autoconf;
    bool NewMountNs;
    std::vector<TCgroup> Cgroups;
    TCred Cred;

    TUnixSocket Sock, MasterSock;
    TUnixSocket Sock2, MasterSock2;
    int ReportStage = 0;

    TError Start();
    void StartChild();

    TError ConfigureChild();
    TError ChildApplyLimits();
    TError WriteResolvConf();
    TError SetHostname();
    TError ApplySysctl();

    TError WaitAutoconf();
    TError ChildExec();

    void ReportPid(pid_t pid);
    void Abort(const TError &error);
};
