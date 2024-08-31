/*
============================================================================
Name: 2.c
Author: M B Ashish
Roll No: MT2024085

Description: 2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.

Date: 31 Aug, 2024.
============================================================================

Output

$ ./a.out &
[1] 18449

/proc/18449$ ls
arch_status  comm                fd                 loginuid    net            patch_state  setgroups     syscall
attr         coredump_filter     fdinfo             map_files   ns             personality  smaps         task
autogroup    cpu_resctrl_groups  gid_map            maps        numa_maps      projid_map   smaps_rollup  timens_offsets
auxv         cpuset              io                 mem         oom_adj        root         stack         timers
cgroup       cwd                 ksm_merging_pages  mountinfo   oom_score      sched        stat          timerslack_ns
clear_refs   environ             ksm_stat           mounts      oom_score_adj  schedstat    statm         uid_map
cmdline      exe                 limits             mountstats  pagemap        sessionid    status        wchan

/proc/18449$ cat status
Name:   a.out
Umask:  0002
State:  R (running)
Tgid:   18449
Ngid:   0
Pid:    18449
PPid:   12694
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 118 1000 
NStgid: 18449
NSpid:  18449
NSpgid: 18449
NSsid:  12694
VmPeak:     2548 kB
VmSize:     2484 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:       768 kB
VmRSS:       768 kB
RssAnon:               0 kB
RssFile:             768 kB
RssShmem:              0 kB
VmData:       92 kB
VmStk:       132 kB
VmExe:         4 kB
VmLib:      1672 kB
VmPTE:        44 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
Threads:        1
SigQ:   0/30461
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ff
Cpus_allowed_list:      0-7
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:      0
voluntary_ctxt_switches:        0
nonvoluntary_ctxt_switches:     696
*/
#include<stdio.h>

int main() {
    for(;;);
}