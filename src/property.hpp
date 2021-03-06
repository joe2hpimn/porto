#pragma once

#include <map>
#include <string>
#include "common.hpp"

constexpr const char *P_RAW_ROOT_PID = "_root_pid";
constexpr const char *P_SEIZE_PID = "seize_pid";
constexpr const char *P_RAW_ID = "_id";
constexpr const char *P_RAW_LOOP_DEV = "_loop_dev";
constexpr const char *P_RAW_NAME = "_name";
constexpr const char *P_RAW_START_TIME = "_start_time";
constexpr const char *P_RAW_DEATH_TIME = "_death_time";

constexpr const char *P_COMMAND = "command";
constexpr const char *P_USER = "user";
constexpr const char *P_GROUP = "group";
constexpr const char *P_OWNER_USER = "owner_user";
constexpr const char *P_OWNER_GROUP = "owner_group";
constexpr const char *P_ENV = "env";
constexpr const char *P_PORTO_NAMESPACE = "porto_namespace";
constexpr const char *P_PLACE = "place";
constexpr const char *P_ROOT = "root";
constexpr const char *P_ROOT_RDONLY = "root_readonly";
constexpr const char *P_CWD = "cwd";
constexpr const char *P_STDIN_PATH = "stdin_path";
constexpr const char *P_STDOUT_PATH = "stdout_path";
constexpr const char *P_STDERR_PATH = "stderr_path";
constexpr const char *P_STDOUT_LIMIT = "stdout_limit";
constexpr const char *P_MEM_GUARANTEE = "memory_guarantee";
constexpr const char *P_MEM_LIMIT = "memory_limit";
constexpr const char *P_DIRTY_LIMIT = "dirty_limit";
constexpr const char *P_ANON_LIMIT = "anon_limit";
constexpr const char *P_HUGETLB_LIMIT = "hugetlb_limit";
constexpr const char *P_RECHARGE_ON_PGFAULT = "recharge_on_pgfault";
constexpr const char *P_CPU_POLICY = "cpu_policy";
constexpr const char *P_CPU_GUARANTEE = "cpu_guarantee";
constexpr const char *P_CPU_LIMIT = "cpu_limit";
constexpr const char *P_CPU_WEIGHT = "cpu_weight";
constexpr const char *P_CPU_SET = "cpu_set";
constexpr const char *D_CPU_SET_AFFINITY  = "cpu_set_affinity";
constexpr const char *P_IO_POLICY = "io_policy";
constexpr const char *P_IO_LIMIT = "io_limit";
constexpr const char *P_IO_OPS_LIMIT = "io_ops_limit";
constexpr const char *P_NET_GUARANTEE = "net_guarantee";
constexpr const char *P_NET_LIMIT = "net_limit";
constexpr const char *P_NET_PRIO = "net_priority";
constexpr const char *P_NET_RX_LIMIT = "net_rx_limit";
constexpr const char *P_RESPAWN = "respawn";
constexpr const char *P_MAX_RESPAWNS = "max_respawns";
constexpr const char *P_ISOLATE = "isolate";
constexpr const char *P_PRIVATE = "private";
constexpr const char *P_ULIMIT = "ulimit";
constexpr const char *P_HOSTNAME = "hostname";
constexpr const char *P_BIND_DNS = "bind_dns";
constexpr const char *P_BIND = "bind";
constexpr const char *P_NET = "net";
constexpr const char *P_NET_TOS = "net_tos";
constexpr const char *P_DEVICES = "devices";
constexpr const char *P_CAPABILITIES = "capabilities";
constexpr const char *P_CAPABILITIES_AMBIENT = "capabilities_ambient";
constexpr const char *P_IP = "ip";
constexpr const char *P_IP_LIMIT = "ip_limit";
constexpr const char *P_DEFAULT_GW = "default_gw";
constexpr const char *P_VIRT_MODE = "virt_mode";
constexpr const char *P_AGING_TIME = "aging_time";
constexpr const char *P_ENABLE_PORTO = "enable_porto";
constexpr const char *P_RESOLV_CONF = "resolv_conf";
constexpr const char *P_WEAK = "weak";
constexpr const char *P_MEM_TOTAL_GUARANTEE = "memory_guarantee_total";
constexpr const char *P_UMASK = "umask";
constexpr const char *P_CONTROLLERS = "controllers";
constexpr const char *P_OOM_IS_FATAL = "oom_is_fatal";
constexpr const char *P_OOM_SCORE_ADJ = "oom_score_adj";
constexpr const char *P_THREAD_LIMIT = "thread_limit";
constexpr const char *P_SYSCTL = "sysctl";
constexpr const char *P_CORE_COMMAND = "core_command";

constexpr const char *D_ABSOLUTE_NAME = "absolute_name";
constexpr const char *D_ABSOLUTE_NAMESPACE = "absolute_namespace";
constexpr const char *D_STATE = "state";
constexpr const char *D_OOM_KILLED = "oom_killed";
constexpr const char *D_PARENT = "parent";
constexpr const char *D_RESPAWN_COUNT = "respawn_count";
constexpr const char *D_ROOT_PID = "root_pid";
constexpr const char *D_EXIT_STATUS = "exit_status";
constexpr const char *D_EXIT_CODE = "exit_code";
constexpr const char *D_STDOUT = "stdout";
constexpr const char *D_STDOUT_OFFSET = "stdout_offset";
constexpr const char *D_STDERR = "stderr";
constexpr const char *D_STDERR_OFFSET = "stderr_offset";
constexpr const char *D_MEMORY_USAGE = "memory_usage";
constexpr const char *D_ANON_USAGE = "anon_usage";
constexpr const char *D_CACHE_USAGE = "cache_usage";
constexpr const char *D_HUGETLB_USAGE = "hugetlb_usage";
constexpr const char *D_MINOR_FAULTS = "minor_faults";
constexpr const char *D_MAJOR_FAULTS = "major_faults";
constexpr const char *D_MAX_RSS = "max_rss";
constexpr const char *D_CPU_USAGE = "cpu_usage";
constexpr const char *D_CPU_SYSTEM = "cpu_usage_system";
constexpr const char *D_CPU_WAIT = "cpu_wait";
constexpr const char *D_NET_CLASS_ID = "net_class_id";
constexpr const char *D_NET_BYTES = "net_bytes";
constexpr const char *D_NET_PACKETS = "net_packets";
constexpr const char *D_NET_DROPS = "net_drops";
constexpr const char *D_NET_OVERLIMITS = "net_overlimits";
constexpr const char *D_NET_RX_BYTES = "net_rx_bytes";
constexpr const char *D_NET_RX_PACKETS = "net_rx_packets";
constexpr const char *D_NET_RX_DROPS = "net_rx_drops";
constexpr const char *D_NET_TX_BYTES = "net_tx_bytes";
constexpr const char *D_NET_TX_PACKETS = "net_tx_packets";
constexpr const char *D_NET_TX_DROPS = "net_tx_drops";
constexpr const char *D_IO_READ = "io_read";
constexpr const char *D_IO_WRITE = "io_write";
constexpr const char *D_IO_OPS = "io_ops";
constexpr const char *D_TIME = "time";
constexpr const char *D_CREATION_TIME = "creation_time";
constexpr const char *D_START_TIME = "start_time";
constexpr const char *D_PORTO_STAT = "porto_stat";
constexpr const char *D_MEM_TOTAL_LIMIT = "memory_limit_total";
constexpr const char *D_CGROUPS = "cgroups";
constexpr const char *D_PROCESS_COUNT = "process_count";
constexpr const char *D_THREAD_COUNT = "thread_count";

enum class EProperty {
    NONE,
    ROOT_PID,
    SEIZE_PID,
    LOOP_DEV,
    START_TIME,
    DEATH_TIME,
    COMMAND,
    USER,
    GROUP,
    OWNER_USER,
    OWNER_GROUP,
    ENV,
    PORTO_NAMESPACE,
    PLACE,
    ROOT,
    ROOT_RDONLY,
    CWD,
    STDIN,
    STDOUT,
    STDERR,
    STDOUT_LIMIT,
    MEM_GUARANTEE,
    MEM_LIMIT,
    DIRTY_LIMIT,
    ANON_LIMIT,
    HUGETLB_LIMIT,
    RECHARGE_ON_PGFAULT,
    CPU_POLICY,
    CPU_GUARANTEE,
    CPU_LIMIT,
    CPU_WEIGHT,
    CPU_SET,
    CPU_SET_AFFINITY,
    IO_POLICY,
    IO_LIMIT,
    IO_OPS_LIMIT,
    NET_GUARANTEE,
    NET_LIMIT,
    NET_PRIO,
    RESPAWN,
    MAX_RESPAWNS,
    ISOLATE,
    PRIVATE,
    ULIMIT,
    HOSTNAME,
    BIND_DNS,
    BIND,
    NET,
    NET_TOS,
    DEVICES,
    CAPABILITIES,
    IP,
    IP_LIMIT,
    DEFAULT_GW,
    VIRT_MODE,
    AGING_TIME,
    ENABLE_PORTO,
    RESOLV_CONF,
    WEAK,
    STATE,
    OOM_KILLED,
    OOM_IS_FATAL,
    OOM_SCORE_ADJ,
    RESPAWN_COUNT,
    EXIT_STATUS,
    CAPABILITIES_AMBIENT,
    UMASK,
    CONTROLLERS,
    THREAD_LIMIT,
    SYSCTL,
    NET_RX_LIMIT,
    CORE_COMMAND,
    NR_PROPERTIES,
};

constexpr const char *P_VIRT_MODE_APP = "app";
constexpr const char *P_VIRT_MODE_OS = "os";
constexpr int VIRT_MODE_APP = 0;
constexpr int VIRT_MODE_OS = 1;
constexpr const char *P_CMD_VIRT_MODE_OS = "/sbin/init";

class TProperty {
public:
    std::string Name;
    EProperty Prop;
    std::string Desc;
    uint64_t RequireControllers = 0;
    bool IsSupported = true;
    bool IsReadOnly = false;
    bool IsHidden = false;
    TError IsAliveAndStopped(void);
    TError IsAlive(void);
    TError IsDead(void);
    TError IsRunning(void);
    TError WantControllers(uint64_t controllers) const;
    TProperty(std::string name, EProperty prop, std::string desc);

    virtual void Init(void) {}

    virtual TError Has();
    virtual TError Get(std::string &value) = 0;
    virtual TError Set(const std::string &value);

    virtual TError GetIndexed(const std::string &index, std::string &value);
    virtual TError SetIndexed(const std::string &index, const std::string &value);

    virtual TError GetToSave(std::string &value);
    virtual TError SetFromRestore(const std::string &value);

    virtual TError Start(void);
};

void InitContainerProperties(void);

class TContainer;
extern __thread TContainer *CT;
extern std::map<std::string, TProperty*> ContainerProperties;
