#!/usr/bin/env bash

COLOR_RED="\e[31m"
COLOR_GREEN="\e[32m"
COLOR_YELLOW="\e[33m"
COLOR_BLUE="\e[34m"
COLOR_RESET="\e[0m"

red_msg() {
  test -n "$1" && echo -en "${COLOR_RED}$1${COLOR_RESET}"
}

green_msg() {
  test -n "$1" && echo -en "${COLOR_GREEN}$1${COLOR_RESET}"
}

yellow_msg() {
  test -n "$1" && echo -en "${COLOR_YELLOW}$1${COLOR_RESET}"
}

blue_msg() {
  test -n "$1" && echo -en "${COLOR_BLUE}$1${COLOR_RESET}"
}
