#!/bin/bash
ARG=$(python3 num_gen.py)
./push_swap "$ARG"
