#!/sbin/sh
# This script is Needed to Set Automatically Device Props.

load_RMX1911()
{
    resetprop "ro.product.model" "Realme 5"
    resetprop "ro.build.product" "RMX1911"
    resetprop "ro.product.device" "RMX1911"
}

load_RMX1927()
{
    resetprop "ro.product.model" "Realme 5 NFC"
    resetprop "ro.build.product" "RMX1927"
    resetprop "ro.product.device" "RMX1927"
}

load_RMX2030()
{
    resetprop "ro.product.model" "Realme 5i"
    resetprop "ro.build.product" "RMX2030"
    resetprop "ro.product.device" "RMX2030"
}


prjName=$(cat /proc/oppoVersion/prjVersion)
echo $prjName

case $prjName in
    "19632")
        load_RMX1927
        ;;
    "19743")
        load_RMX2030
        ;;        
    *)
        load_RMX1911
        ;;
esac

exit 0