#!/bin/bash
havegcc=0
haverl=0
havear=0

AR=ar
RL=ranlib
GCC=gcc

for arg in "$@"; do
    case $arg in
        AR=*)
            AR="${arg#*=}"
            ;;
        RL=*)
            RL="${arg#*=}"
            ;;
        GCC=*)
            GCC="${arg#*=}"
            ;;
    esac
done

printf	"\n"
echo "Checking for $GCC"
which $GCC
if [ "$?" = "0" ]; then
    havegcc=1
    echo "Found GCC"
else
    echo "GCC Not Found or Broken"
    exit 1
fi

printf	"\n"
echo "Checking for $AR"
which $AR
if [ "$?" = "0" ]; then
    havear=1
    echo "Found AR"
else
    echo "AR Not Found or Broken"
    exit 1
fi

printf "\n"
echo "Checking for $RL"
which $RL
if [ "$?" = "0" ]; then
    haverl=1
    echo "Found Ranlib"
else
    echo "Ranlib Not Found or Broken"
    exit 1
fi
printf "\n\n"
echo "$GCC"
echo "$RL"
echo "$AR"

echo "All required tools found & working"
cat > env.sh <<EOF
AR=$AR
CC=$GCC
RL=$RL
EOF

chmod +x env.sh
echo 'You can now build with `make $(cat env.sh)`'
