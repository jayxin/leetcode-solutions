#!/usr/bin/env bash

set -e

SCRIPT_DIR=$(dirname ${BASH_SOURCE[0]})

source $SCRIPT_DIR/../utils/colors.sh

PHASE="run"

printf "%s started.\n" $(blue_msg "[$PHASE]")

INS_DIR=$PWD/inputs
OUTS_DIR=$PWD/outputs

test -d $OUTS_DIR || mkdir $OUTS_DIR

for input_file in $(find $INS_DIR -type f) ; do
  file_name=$(basename $input_file)
  ./main < $input_file > $OUTS_DIR/$file_name
done

printf "%s done.\n" $(blue_msg "[$PHASE]")
printf "\n"
