# Round-robin (RR) scheduling
# each task is run for a time quantum (or for the remainder of its CPU burst).
# This is pre-emptive by default.
# The length of a time quantum is 10 milliseconds. It never changes from this value.

'''
Author: Martin Derwin
Student Number: 20439162
FileName: schedule_rr.py
Functions: main, get_tasks, store_bursts, calculate_process_info,
           waiting_time_sum, turn_around_time_average, waiting_time_average, print_process_info

Acknowledgement:
    I have read and undestood the DCU Academic Integrity and Plagiarism Policy, found here: https://www.dcu.ie/policies/academic-integrity-plagiarism-policy
    This is my own work. This assignment, or any part of it, has not been previously submitted by me/us or any other person for assessment on this or any other course of study.
'''

from utility import *
import sys

def main():

    quantum = 10                                    # length of a time quantum is 10ms

    ta_time = 0                                     # turn-around time
    count_tasks = 0                                 # number of tasks
    ta_time_sum = 0                                 # total turn-around time
    wt_sum = 0                                      # waiting time sum

    Task_list = get_tasks(sys.argv[1])              # open file and append content to list

    Task_bursts = store_bursts(Task_list)           # need to store the burst times in a dictionary

    for Tn, priority, burst in Task_list:
        if quantum < burst:                         # process runs for at most 10ms
            ms_left = burst - quantum               # calculate time left
            ta_time += quantum                      # add 10ms to turn around time
            process = Tn, priority, ms_left
            Task_list.append(process)               # add the process to the end of the list
        else:
            ta_time_sum, count_tasks, ta_time = calculate_process_info(ta_time, count_tasks, ta_time_sum, burst)
            print_process_info(Tn, Task_bursts[Tn], ta_time)
            wt_sum = waiting_time_sum(wt_sum, ta_time, Task_bursts[Tn])

    turn_around_time_average(ta_time_sum, count_tasks)
    waiting_time_average(wt_sum, count_tasks)



if __name__ == "__main__":
    main()
