#!/usr/bin/env bash

set -e

SCRIPT_DIR=$(dirname ${BASH_SOURCE[0]})

source $SCRIPT_DIR/utils/colors.sh

PHASE="check"

printf "%s started.\n" $(blue_msg "[$PHASE]")

STDS_DIR=$PWD/stds
OUTS_DIR=$PWD/outputs

for out_file in $(find $OUTS_DIR/* -type f) ; do
  file_name=$(basename $out_file)
  STD_FILE_PATH=$STDS_DIR/$file_name
  OUT_FILE_PATH=$out_file

  if [ -f $STD_FILE_PATH ] ; then
    printf "%s: stds/$file_name outputs/$file_name\n" $(yellow_msg "Checking")

    diff $STD_FILE_PATH $OUT_FILE_PATH

    if [ $? -eq 0 ] ; then
      printf "%s: stds/$file_name outputs/$file_name\n" $(green_msg "PASS")
    else
      printf "%s: stds/$file_name outputs/$file_name\n" $(red_msg "DIFFER")
      exit 1
    fi

    printf "\n"
  fi
done

printf "%s done.\n" $(blue_msg "[$PHASE]")
printf "\n"
