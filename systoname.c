#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>

const char* syscall_name(long int syscall_number) {
    switch(syscall_number) {
        case 0: return "SYS_read";
        case 1: return "SYS_write";
        case 2: return "SYS_open";
        case 3: return "SYS_close";
        case 4: return "SYS_stat";
        case 5: return "SYS_fstat";
        case 6: return "SYS_lstat";
        case 7: return "SYS_poll";
        case 8: return "SYS_lseek";
        case 9: return "SYS_mmap";
        case 10: return "SYS_mprotect";
        case 11: return "SYS_munmap";
        case 12: return "SYS_brk";
        case 13: return "SYS_rt_sigaction";
        case 14: return "SYS_rt_sigprocmask";
        case 15: return "SYS_rt_sigreturn";
        case 16: return "SYS_ioctl";
        case 17: return "SYS_pread64";
        case 18: return "SYS_pwrite64";
        case 19: return "SYS_readv";
        case 20: return "SYS_writev";
        case 21: return "SYS_access";
        case 22: return "SYS_pipe";
        case 23: return "SYS_select";
        case 24: return "SYS_sched_yield";
        case 25: return "SYS_mremap";
        case 26: return "SYS_msync";
        case 27: return "SYS_mincore";
        case 28: return "SYS_madvise";
        case 29: return "SYS_shmget";
        case 30: return "SYS_shmat";
        case 31: return "SYS_shmctl";
        case 32: return "SYS_dup";
        case 33: return "SYS_dup2";
        case 34: return "SYS_pause";
        case 35: return "SYS_nanosleep";
        case 36: return "SYS_getitimer";
        case 37: return "SYS_alarm";
        case 38: return "SYS_setitimer";
        case 39: return "SYS_getpid";
        case 40: return "SYS_sendfile";
        case 41: return "SYS_socket";
        case 42: return "SYS_connect";
        case 43: return "SYS_accept";
        case 44: return "SYS_sendto";
        case 45: return "SYS_recvfrom";
        case 46: return "SYS_sendmsg";
        case 47: return "SYS_recvmsg";
        case 48: return "SYS_shutdown";
        case 49: return "SYS_bind";
        case 50: return "SYS_listen";
        case 51: return "SYS_getsockname";
        case 52: return "SYS_getpeername";
        case 53: return "SYS_socketpair";
        case 54: return "SYS_setsockopt";
        case 55: return "SYS_getsockopt";
        case 56: return "SYS_clone";
        case 57: return "SYS_fork";
        case 58: return "SYS_vfork";
        case 59: return "SYS_execve";
        case 60: return "SYS_exit";
        case 61: return "SYS_wait4";
        case 62: return "SYS_kill";
        case 63: return "SYS_uname";
        case 64: return "SYS_semget";
        case 65: return "SYS_semop";
        case 66: return "SYS_semctl";
        case 67: return "SYS_shmdt";
        case 68: return "SYS_msgget";
        case 69: return "SYS_msgsnd";
        case 70: return "SYS_msgrcv";
        case 71: return "SYS_msgctl";
        case 72: return "SYS_fcntl";
        case 73: return "SYS_flock";
        case 74: return "SYS_fsync";
        case 75: return "SYS_fdatasync";
        case 76: return "SYS_truncate";
        case 77: return "SYS_ftruncate";
        case 78: return "SYS_getdents";
        case 79: return "SYS_getcwd";
        case 80: return "SYS_chdir";
        case 81: return "SYS_fchdir";
        case 82: return "SYS_rename";
        case 83: return "SYS_mkdir";
        case 84: return "SYS_rmdir";
        case 85: return "SYS_creat";
        case 86: return "SYS_link";
        case 87: return "SYS_unlink";
        case 88: return "SYS_symlink";
        case 89: return "SYS_readlink";
        case 90: return "SYS_chmod";
        case 91: return "SYS_fchmod";
        case 92: return "SYS_chown";
        case 93: return "SYS_fchown";
        case 94: return "SYS_lchown";
        case 95: return "SYS_umask";
        case 96: return "SYS_gettimeofday";
        case 97: return "SYS_getrlimit";
        case 98: return "SYS_getrusage";
        case 99: return "SYS_sysinfo";
        case 100: return "SYS_times";
         case 101: return "SYS_ptrace";
        case 102: return "SYS_getuid";
        case 103: return "SYS_syslog";
        case 104: return "SYS_getgid";
        case 105: return "SYS_setuid";
        case 106: return "SYS_setgid";
        case 107: return "SYS_geteuid";
        case 108: return "SYS_getegid";
        case 109: return "SYS_setpgid";
        case 110: return "SYS_getppid";
        case 111: return "SYS_getpgrp";
        case 112: return "SYS_setsid";
        case 113: return "SYS_setreuid";
        case 114: return "SYS_setregid";
        case 115: return "SYS_getgroups";
        case 116: return "SYS_setgroups";
        case 117: return "SYS_setresuid";
        case 118: return "SYS_getresuid";
        case 119: return "SYS_setresgid";
        case 120: return "SYS_getresgid";
        case 121: return "SYS_getpgid";
        case 122: return "SYS_setfsuid";
        case 123: return "SYS_setfsgid";
        case 124: return "SYS_getsid";
        case 125: return "SYS_capget";
        case 126: return "SYS_capset";
        case 127: return "SYS_rt_sigpending";
        case 128: return "SYS_rt_sigtimedwait";
        case 129: return "SYS_rt_sigqueueinfo";
        case 130: return "SYS_rt_sigsuspend";
        case 131: return "SYS_sigaltstack";
        case 132: return "SYS_utime";
        case 133: return "SYS_mknod";
        case 134: return "SYS_uselib";
        case 135: return "SYS_personality";
        case 136: return "SYS_ustat";
        case 137: return "SYS_statfs";
        case 138: return "SYS_fstatfs";
        case 139: return "SYS_sysfs";
        case 140: return "SYS_getpriority";
        case 141: return "SYS_setpriority";
        case 142: return "SYS_sched_setparam";
        case 143: return "SYS_sched_getparam";
        case 144: return "SYS_sched_setscheduler";
        case 145: return "SYS_sched_getscheduler";
        case 146: return "SYS_sched_get_priority_max";
        case 147: return "SYS_sched_get_priority_min";
        case 148: return "SYS_sched_rr_get_interval";
        case 149: return "SYS_mlock";
        case 150: return "SYS_munlock";
        case 151: return "SYS_mlockall";
        case 152: return "SYS_munlockall";
        case 153: return "SYS_vhangup";
        case 154: return "SYS_modify_ldt";
        case 155: return "SYS_pivot_root";
        case 156: return "SYS__sysctl";
        case 157: return "SYS_prctl";
        case 158: return "SYS_arch_prctl";
        case 159: return "SYS_adjtimex";
        case 160: return "SYS_setrlimit";
        case 161: return "SYS_chroot";
        case 162: return "SYS_sync";
        case 163: return "SYS_acct";
        case 164: return "SYS_settimeofday";
        case 165: return "SYS_mount";
        case 166: return "SYS_umount2";
        case 167: return "SYS_swapon";
        case 168: return "SYS_swapoff";
        case 169: return "SYS_reboot";
        case 170: return "SYS_sethostname";
        case 171: return "SYS_setdomainname";
        case 172: return "SYS_iopl";
        case 173: return "SYS_ioperm";
        case 174: return "SYS_create_module";
        case 175: return "SYS_init_module";
        case 176: return "SYS_delete_module";
        case 177: return "SYS_get_kernel_syms";
        case 178: return "SYS_query_module";
        case 179: return "SYS_quotactl";
        case 180: return "SYS_nfsservctl";
        case 181: return "SYS_getpmsg";
        case 182: return "SYS_putpmsg";
        case 183: return "SYS_afs_syscall";
        case 184: return "SYS_tuxcall";
        case 185: return "SYS_security";
        case 186: return "SYS_gettid";
        case 187: return "SYS_readahead";
        case 188: return "SYS_setxattr";
        case 189: return "SYS_lsetxattr";
        case 190: return "SYS_fsetxattr";
        case 191: return "SYS_getxattr";
        case 192: return "SYS_lgetxattr";
        case 193: return "SYS_fgetxattr";
        case 194: return "SYS_listxattr";
        case 195: return "SYS_llistxattr";
        case 196: return "SYS_flistxattr";
        case 197: return "SYS_removexattr";
        case 198: return "SYS_lremovexattr";
        case 199: return "SYS_fremovexattr";
        case 200: return "SYS_tkill";
        case 201: return "SYS_time";
        case 202: return "SYS_futex";
        case 203: return "SYS_sched_setaffinity";
        case 204: return "SYS_sched_getaffinity";
        case 205: return "SYS_set_thread_area";
        case 206: return "SYS_io_setup";
        case 207: return "SYS_io_destroy";
        case 208: return "SYS_io_getevents";
        case 209: return "SYS_io_submit";
        case 210: return "SYS_io_cancel";
        case 211: return "SYS_get_thread_area";
        case 212: return "SYS_lookup_dcookie";
        case 213: return "SYS_epoll_create";
        case 214: return "SYS_epoll_ctl_old";
        case 215: return "SYS_epoll_wait_old";
        case 216: return "SYS_remap_file_pages";
        case 217: return "SYS_getdents64";
        case 218: return "SYS_set_tid_address";
        case 219: return "SYS_restart_syscall";
        case 220: return "SYS_semtimedop";
        case 221: return "SYS_fadvise64";
        case 222: return "SYS_timer_create";
        case 223: return "SYS_timer_settime";
        case 224: return "SYS_timer_gettime";
        case 225: return "SYS_timer_getoverrun";
        case 226: return "SYS_timer_delete";
        case 227: return "SYS_clock_settime";
        case 228: return "SYS_clock_gettime";
        case 229: return "SYS_clock_getres";
        case 230: return "SYS_clock_nanosleep";
        case 231: return "SYS_exit_group";
        case 232: return "SYS_epoll_wait";
        case 233: return "SYS_epoll_ctl";
        case 234: return "SYS_tgkill";
        case 235: return "SYS_utimes";
        case 236: return "SYS_vserver";
        case 237: return "SYS_mbind";
        case 238: return "SYS_set_mempolicy";
        case 239: return "SYS_get_mempolicy";
        case 240: return "SYS_mq_open";
        case 241: return "SYS_mq_unlink";
        case 242: return "SYS_mq_timedsend";
        case 243: return "SYS_mq_timedreceive";
        case 244: return "SYS_mq_notify";
        case 245: return "SYS_mq_getsetattr";
        case 246: return "SYS_kexec_load";
        case 247: return "SYS_waitid";
        case 248: return "SYS_add_key";
        case 249: return "SYS_request_key";
        case 250: return "SYS_keyctl";
        case 251: return "SYS_ioprio_set";
        case 252: return "SYS_ioprio_get";
        case 253: return "SYS_inotify_init";
        case 254: return "SYS_inotify_add_watch";
        case 255: return "SYS_inotify_rm_watch";
        case 256: return "SYS_migrate_pages";
        case 257: return "SYS_openat";
        case 258: return "SYS_mkdirat";
        case 259: return "SYS_mknodat";
        case 260: return "SYS_fchownat";
        case 261: return "SYS_futimesat";
        case 262: return "SYS_newfstatat";
        case 263: return "SYS_unlinkat";
        case 264: return "SYS_renameat";
        case 265: return "SYS_linkat";
        case 266: return "SYS_symlinkat";
        case 267: return "SYS_readlinkat";
        case 268: return "SYS_fchmodat";
        case 269: return "SYS_faccessat";
        case 270: return "SYS_pselect6";
        case 271: return "SYS_ppoll";
        case 272: return "SYS_unshare";
        case 273: return "SYS_set_robust_list";
        case 274: return "SYS_get_robust_list";
        case 275: return "SYS_splice";
        case 276: return "SYS_tee";
        case 277: return "SYS_sync_file_range";
        case 278: return "SYS_vmsplice";
        case 279: return "SYS_move_pages";
        case 280: return "SYS_utimensat";
        case 281: return "SYS_epoll_pwait";
        case 282: return "SYS_signalfd";
        case 283: return "SYS_timerfd_create";
        case 284: return "SYS_eventfd";
        case 285: return "SYS_fallocate";
        case 286: return "SYS_timerfd_settime";
        case 287: return "SYS_timerfd_gettime";
        case 288: return "SYS_accept4";
        case 289: return "SYS_signalfd4";
        case 290: return "SYS_eventfd2";
        case 291: return "SYS_epoll_create1";
        case 292: return "SYS_dup3";
        case 293: return "SYS_pipe2";
        case 294: return "SYS_inotify_init1";
        case 295: return "SYS_preadv";
        case 296: return "SYS_pwritev";
        case 297: return "SYS_rt_tgsigqueueinfo";
        case 298: return "SYS_perf_event_open";
        case 299: return "SYS_recvmmsg";
        case 300: return "SYS_fanotify_init";
        case 301: return "SYS_fanotify_mark";
        case 302: return "SYS_prlimit64";
        case 303: return "SYS_name_to_handle_at";
        case 304: return "SYS_open_by_handle_at";
        case 305: return "SYS_clock_adjtime";
        case 306: return "SYS_syncfs";
        case 307: return "SYS_sendmmsg";
        case 308: return "SYS_setns";
        case 309: return "SYS_getcpu";
        case 310: return "SYS_process_vm_readv";
        case 311: return "SYS_process_vm_writev";
        case 312: return "SYS_kcmp";
        case 313: return "SYS_finit_module";
        case 314: return "SYS_sched_setattr";
        case 315: return "SYS_sched_getattr";
        case 316: return "SYS_renameat2";
        case 317: return "SYS_seccomp";
        case 318: return "SYS_getrandom";
        case 319: return "SYS_memfd_create";
        case 320: return "SYS_kexec_file_load";
        case 321: return "bpf";
        case 322: return "execveat";
        case 323: return "SYS_userfaultfd";
        case 324: return "SYS_membarrier";
        case 325: return "SYS_mlock2";
        case 326: return "SYS_copy_file_range";
        case 327: return "SYS_preadv2";
        case 328: return "SYS_pwritev2";
        case 329: return "SYS_pkey_mprotect";
        case 330: return "SYS_pkey_alloc";
        case 331: return "SYS_pkey_free";
        case 332: return "SYS_statx";
        case 333: return "SYS_rseq";
        case 334: return "SYS_io_pgetevents";
        case 335: return "SYS_pidfd_send_signal";
        case 336: return "SYS_io_uring_setup";
        case 337: return "SYS_io_uring_enter";
        case 338: return "SYS_io_uring_register";
        case 339: return "SYS_open_tree";
        case 340: return "SYS_move_mount";
        // Add more cases as needed
        
        default: return "Unknown syscall";
    }
}
