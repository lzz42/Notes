# coding=utf-8

import os
import sys
import psutil

mProc = 'desktop.exe'
mProcs = 'desktop'
mFile = '..\\RX\Record.txt'
mOutFile = '..\\PY_RXX\\ROut.txt'
replay = "test?r=replay&file={_file}&outfile={_outfile}"

def existsProc(processname):
    pl = psutil.pids()
    for pid in pl:
        if psutil.Process(pid).name() == processname:
            print(pid)
            break
    else:
        print("not found")


def findPid(processname):
    pl = psutil.pids()
    for pid in pl:
        if psutil.Process(pid).name() == processname:
            print(pid)
            return pid
            break
    else:
        print("not found")
    return 0


def killProc(pid):
    if pid < 0:
        return False
    if pid == 0:
        # According to "man 2 kill" PID 0 refers to every process
        # in the process group of the calling process.
        # On certain systems 0 is a valid PID but we have no way
        # to know that in a portable fashion.
        raise ValueError('invalid PID 0')
    try:
        os.kill(pid, 0)
    except OSError as err:
        if err.errno == errno.ESRCH:
            # ESRCH == No such process
            return False
        elif err.errno == errno.EPERM:
            # EPERM clearly means there's a process to deny access to
            return True
        else:
            # According to "man 2 kill" possible error values are
            # (EINVAL, EPERM, ESRCH)
            raise
    else:
        return True


def startProc(file, arg):
    main = "file " + arg
    r_v = os.system(main)
    print(r_v)


if __name__ == "__main__":
    pid = findPid(mProcs)
    while pid > 0:
        killProc(pid)
        time.sleep(100)
        pid = findPid(mProcs)
    arg = replay.format(_file=mFile,_outfile=mOutFile)
    for i in range(0,5):
        startProc(mProc,arg)
        print('Test loop {_t}'.format(_t=i))
        while existsProc(mProcs):
            time.sleep(100)
    print('all test done')
    pass
