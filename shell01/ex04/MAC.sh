ifconfig | grep ether | sed 's/^\s*/ /g' | cut -d' ' -f 3
