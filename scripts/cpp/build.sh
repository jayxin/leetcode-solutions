#!/usr/bin/env bash

set -e

SCRIPT_DIR=$(dirname ${BASH_SOURCE[0]})

source $SCRIPT_DIR/../utils/colors.sh

PHASE="build"

printf "%s started.\n" $(blue_msg "[$PHASE]")

g++ -o main main.cc

printf "%s done.\n" $(blue_msg "[$PHASE]")
printf "\n"
