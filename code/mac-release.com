echo "<<< OpenSplice HDE Release V6.4.140320OSS For x86_64.linux, Date 2014-03-19 >>>"
if [ "${SPLICE_ORB:=}" = "" ]
then
    SPLICE_ORB=DDS_OpenFusion_2
    export SPLICE_ORB
fi
if [ "${SPLICE_JDK:=}" = "" ]
then
    SPLICE_JDK=jdk
    export SPLICE_JDK
fi
OSPL_HOME="/opt/OpenSplice/opensplice-OSPL_V6_4_OSS_RELEASE"
PATH=$OSPL_HOME/bin:$PATH
LD_LIBRARY_PATH=$OSPL_HOME/lib${LD_LIBRARY_PATH:+:}$LD_LIBRARY_PATH
CPATH=$OSPL_HOME/include:$OSPL_HOME/include/sys:${CPATH:=}
OSPL_URI=file:/ospl.xml
OSPL_TMPL_PATH=$OSPL_HOME/etc/idlpp
. $OSPL_HOME/etc/java/defs.$SPLICE_JDK
export OSPL_HOME PATH LD_LIBRARY_PATH CPATH OSPL_TMPL_PATH OSPL_URI
