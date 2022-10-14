# Priority scheduling
# schedules tasks based on priority.

'''
Author: Martin Derwin
Student Number: 20439162
FileName: schedule_priority.py
Functions: main, get_tasks, priority_sort, calculate_process_info,
           waiting_time_sum, turn_around_time_average, waiting_time_average, print_process_info

Acknowledgement:
    I have read and undestood the DCU Academic Integrity and Plagiarism Policy, found here: https://www.dcu.ie/policies/academic-integrity-plagiarism-policy
    This is my own work. This assignment, or any part of it, has not been previously submitted by me/us or any other person for assessment on this or any other course of study.
'''

from utility import *
import sys

def main():

    ta_time = 0                                     # turn-around time
    count_tasks = 0                                 # number of tasks
    ta_time_sum = 0                                 # total turn-around time
    wt_sum = 0                                      # waiting time sum

    Task_list = get_tasks(sys.argv[1])              # returns a list of tasks taken from a file (command line argument)

    Priority_Tasks = priority_sort(Task_list)       # sort the list by priority

    for Tn, priority, burst in Priority_Tasks:      # for each task in the list
        ta_time_sum, count_tasks, ta_time = calculate_process_info(ta_time, count_tasks, ta_time_sum, burst)
        print_process_info(Tn, burst, ta_time)
        wt_sum = waiting_time_sum(wt_sum, ta_time, burst)

    turn_around_time_average(ta_time_sum, count_tasks)
    waiting_time_average(wt_sum, count_tasks)

def priority_sort(Task_list):
    sorted_Tasks = sorted(Task_list, key=lambda item: item[1], reverse=True) # sort using priority as key, reverse list order
    return sorted_Tasks


if __name__ == "__main__":
    main()