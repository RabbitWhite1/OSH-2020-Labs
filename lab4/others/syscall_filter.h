#ifndef __SYSCALL_FILTER_H
#define __SYSCALL_FILTER_H
#include <seccomp.h>        // For seccomp series functions
#include <stdio.h>
#include "utility.h"
#define __TIMESIZE 64

void set_seccomp() {
    scmp_filter_ctx ctx;

    ctx = seccomp_init(SCMP_ACT_KILL);
    if (ctx == NULL)
            goto out;

    // line 54 names 
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(accept), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(accept4), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(access), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(adjtimex), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(alarm), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(bind), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(brk), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(capget), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(capset), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chdir), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chmod), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chown), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chown32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_getres), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_gettime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_nanosleep), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(connect), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(copy_file_range), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(creat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup3), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_create), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_create1), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_ctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_ctl_old), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_pwait), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_wait), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_wait_old), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(eventfd), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(eventfd2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execveat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(faccessat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fadvise64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fadvise64_64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fallocate), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fanotify_mark), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchdir), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchmod), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchmodat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchown), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchown32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchownat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fcntl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fcntl64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fdatasync), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fgetxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(flistxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(flock), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fork), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fremovexattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fsetxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatat64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatfs), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatfs64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fsync), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ftruncate), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ftruncate64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(futex), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(futimesat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getcpu), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getcwd), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getdents), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getdents64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getegid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getegid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(geteuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(geteuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgroups), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgroups32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getitimer), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpeername), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpgrp), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getppid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpriority), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrandom), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresgid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrlimit), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(get_robust_list), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrusage), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsockname), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsockopt), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(get_thread_area), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(gettid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(gettimeofday), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_add_watch), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_init), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_init1), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_rm_watch), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_cancel), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_destroy), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_getevents), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_pgetevents), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioprio_get), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioprio_set), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_setup), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(io_submit), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ipc), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(kill), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lchown), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lchown32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lgetxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(link), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(linkat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(listen), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(listxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(llistxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(_llseek), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lremovexattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lseek), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lsetxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lstat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lstat64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(madvise), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(memfd_create), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mincore), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mkdir), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mkdirat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknod), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknodat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlock), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlock2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlockall), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_getsetattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_notify), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_open), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_timedreceive), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_timedsend), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_unlink), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mremap), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgget), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgrcv), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgsnd), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msync), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munlock), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munlockall), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munmap), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(nanosleep), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(newfstatat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(_newselect), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pause), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pipe), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pipe2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(poll), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ppoll), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(prctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pread64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(preadv), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(preadv2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(prlimit64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pselect6), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwrite64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwritev), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwritev2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readahead), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readlink), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readlinkat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readv), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recv), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvfrom), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvmmsg), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvmsg), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(remap_file_pages), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(removexattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rename), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(renameat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(renameat2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(restart_syscall), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rmdir), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigaction), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigpending), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigprocmask), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigqueueinfo), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigsuspend), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigtimedwait), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_tgsigqueueinfo), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getaffinity), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getparam), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_get_priority_max), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_get_priority_min), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getscheduler), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_rr_get_interval), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setaffinity), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setparam), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setscheduler), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_yield), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(seccomp), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(select), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semget), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semop), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semtimedop), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(send), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendfile), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendfile64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendmmsg), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendmsg), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendto), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsgid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgroups), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgroups32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setitimer), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setpgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setpriority), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setregid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setregid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresgid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresgid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setreuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setreuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setrlimit), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_robust_list), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setsid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setsockopt), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_thread_area), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_tid_address), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setuid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setuid32), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setxattr), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmctl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmdt), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmget), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shutdown), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigaltstack), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(signalfd), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(signalfd4), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigprocmask), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigreturn), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socketcall), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socketpair), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(splice), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(stat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(stat64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statfs), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statfs64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statx), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(symlink), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(symlinkat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sync), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sync_file_range), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(syncfs), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sysinfo), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tee), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tgkill), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(time), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_create), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_delete), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_getoverrun), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_gettime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_settime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_create), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_gettime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_settime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(times), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tkill), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(truncate), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(truncate64), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ugetrlimit), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(umask), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(uname), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unlink), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unlinkat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utime), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utimensat), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utimes), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(vfork), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(vmsplice), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(wait4), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(waitid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(waitpid), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(writev), 0)) goto out;

    // arch_prctl
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(arch_prctl), 0);
    // modify_ldt
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(modify_ldt), 0);

    // line 586 names
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(bpf), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clone), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fanotify_init), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lookup_dcookie), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mount), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(name_to_handle_at), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(perf_event_open), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(quotactl), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setdomainname), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sethostname), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setns), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(syslog), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(umount), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(umount2), 0)) goto out;
    if(seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unshare), 0)) goto out;

    seccomp_load(ctx);
    seccomp_release(ctx);
    logger("info", "seccmop successfully finished!\n");
    return;
out:
    seccomp_release(ctx);
    errexit("[container][error] syscall_filter failed! ");
}


#endif