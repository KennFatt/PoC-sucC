/**
 * Operating System Identifier (OSID) is a C header file to identicate an operating system on specific machine.
 * @author @KennFatt (https://github.com/KennFatt)
 */
#ifndef __os_identifier_h
#define __os_identifier_h 1

#ifdef _AIX
# define OS_ID "AIX"
#elif __ANDROID__
# define OS_ID "Android"
#elif UTS
# define OS_ID "Amdahl UTS"
#elif AMIGA
# define OS_ID "AmigaOS"
#elif aegis
# define OS_ID "Apollo AEGIS"
#elif apollo
# define OS_ID "Apollo Domain"
#elif __BEOS__
# define OS_ID "BeOS"
#elif __bg__
# define OS_ID "Blue Gene"
#elif __bsdi__
# define OS_ID "BSD"
#elif __convex__
# define OS_ID "ConvexOS"
#elif __CYGWIN__
# define OS_ID "Cygwin"
#elif DGUX || __DGUX__ || __dgux__
# define OS_ID "DGUX"
#elif __DragonFly__
# define OS_ID "DragonFly"
#elif _SEQUENT_ || sequent
# define OS_ID "DYNIX"
#elif __ECOS
# define OS_ID "eCos"
#elif __EMX__
# define OS_ID "EMX"
#elif __FreeBSD_kernel__ && __GLIBC__
# define OS_ID "GNU/kFreeBSD"
#elif __FreeBSD__ || __FreeBSD_kernel__
# define OS_ID "FreeBSD"
#elif __GNU__ || __gnu_hurd__
# define OS_ID "GNU"
#elif __gnu_linux__
# define OS_ID "GNU/Linux"
#elif __hiuxmpp
# define OS_ID "HIUX MPP"
#elif _hpux || hpux || __hpux
# define OS_ID "HPUX"
#elif __OS400__
# define OS_ID "IBM OS400"
#elif __INTEGRITY
# define OS_ID "INTEGRITY"
#elif __INTERIX
# define OS_ID "Interix"
#elif sgi || __sgi
# define OS_ID "IRIX"
#elif __linux__ || __linux || linux
# define OS_ID "Linux"
#elif __Lynx__
# define OS_ID "LynxOS"
#elif machintosh || Machintosh || (__APPLE__ && __MACH__)
# define OS_ID "MacOS"
#elif __0S9000 || _OSK
# define OS_ID "Microware OS9"
#elif __minix
# define OS_ID "MINIX"
#elif __MORPHOS__
# define OS_ID "MorphOS"
#elif mpeix || __mpexl
# define OS_ID "MPEiX"
#elif MSDOS || __MSDOS__ || _MSDOS || __DOS__
# define OS_ID "MSDOS"
#elif __NetBSD__
# define OS_ID "NetBSD"
#elif __TANDEM
# define OS_ID "NonStop"
#elif __nucleus__
# define OS_ID "Nucleus RTOS"
#elif __OpenBSD__
# define OS_ID  "OpenBSD"
#elif OS2 || _OS2 || __OS2__ || __TOS_OS2__
# define OS_ID "OS2"
#elif __palmos__
# define OS_ID "Palm OS"
#elif EPLAN9
# define OS_ID "Plan 9"
#elif pyr
# define OS_ID "Pyramid DC"
#elif __QNX__ || __QNXNTO__
# define OS_ID "QNX"
#elif sinux
# define OS_ID "Reliant UNIX"
#elif M_I386 || M_XENIX || _SCO_DS
# define OS_ID "SCO OpenServer"
#elif sun || __sun
# ifdef __SVR4 || __svr4__
#  define OS_ID "Solaris"
# else
#  define OS_ID "SunOS"
# endif
#elif __VOS__
# define OS_ID "Stratus VOS"
#elif __sysv__ || __SVR4 || __svr4__ || _SYSTYPE_SVR4
# define OS_ID "SVR4 Family"
#elif __SYLLABLE__
# define OS_ID "Syllable"
#elif __SYMBIAN32__
# define OS_ID "Symbian OS"
#elif __osf__ || __osf
# define OS_ID "Tru64"
#elif ultrix || __ultrix || __ultrix__ || (unix && vax)
# define OS_ID "Ultrix"
#elif _UNICOS
# define OS_ID "UNICOS"
#elif _CRAY
# define OS_ID "UNICOX mp"
#elif __unix__ || __unix
# define OS_ID "Unix Family"
#elif sco || _UNIXWARE7
# define OS_ID "UnixWare"
#elif _UWIN
# define OS_ID "UWin Family"
#elif VMS || __VMS
# define OS_ID "VMS"
#elif __VXWORKS__ || __vxworks
# define OS_ID "VxWorks"
#elif _WIN16 || _WIN32 || _WIN64 || __WIN32__ || __TOS_WIN__ || __WINDOWS__
# define OS_ID "Windows"
#elif _WIN32_WCE
# define OS_ID "Windows CE"
#elif _WINDU_SOURCE
# define OS_ID "WindU Family"
#elif __MVS__ || __HOS_MVS__ || __TOS_MVS__
# define OS_ID "Z OS"
#else
# define OS_ID "Undefined"
#endif

#endif