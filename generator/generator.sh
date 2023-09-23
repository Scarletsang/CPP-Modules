#!/bin/bash

if [ -z "$1" ]; then
    echo "Argument \$1 is empty. Expected the name of the exercise module"
    exit 1
fi

if [ -z "$2" ]; then
    echo "Argument \$2 is empty. Expected the amount of exercises in the module"
    exit 1
fi

BASH_SCRIPT_LOCATION=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

cd $BASH_SCRIPT_LOCATION/..

git submodule add https://github.com/Scarletsang/CPP-Modules.git src/$1
cd src/$1
git checkout -b $1
rm -r .vscode/ src/ docs/ generator/ .gitmodules README.md
for ((i = 0; i <= $2; i++)); do
    mkdir ex0$i
    cp $BASH_SCRIPT_LOCATION/template/* ex0$i
done
