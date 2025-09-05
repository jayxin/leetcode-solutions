#!/usr/bin/env bash

set -e

SCRIPT_DIR=$(dirname ${BASH_SOURCE[0]})

source $SCRIPT_DIR/utils/colors.sh

PHASE="clean"

printf "%s started.\n" $(blue_msg "[$PHASE]")

test -d $PWD/outputs && rm -r $PWD/outputs
test -f main && rm main

printf "%s done.\n" $(blue_msg "[$PHASE]")
printf "\n"
