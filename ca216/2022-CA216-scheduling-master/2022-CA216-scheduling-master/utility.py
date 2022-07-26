# Common Code

'''
Author: Martin Derwin
Student Number: 20439162
FileName: utility.py
Functions: get_tasks, make_dict, store_bursts, turn_around_time_average, calculate_process_info, print_process_info
           waiting_time_sum, waiting_time_average

Acknowledgement:
    I have read and undestood the DCU Academic Integrity and Plagiarism Policy, found here: https://www.dcu.ie/policies/academic-integrity-plagiarism-policy
    This is my own work. This assignment, or any part of it, has not been previously submitted by me/us or any other person for assessment on this or any other course of study.
'''

def get_tasks(file):
    try:
        with open(file) as f:                   # open file
                Task_list = []
                for line in f:                  # for each line in the file
                    line = line.strip()         # strip line of whitespace/ newline

                    if len(line.split(", ")) != 3:      # error check for number of elements per line
                        msg = "The file " + file + " does not contain the appropriate number of elements per line"
                        example = "see the line: " + str(line.split(", "))
                        print(msg)
                        print(example)
                        exit(0)

                    Tn, priority, burst = line.split(", ") # get Task number, priority and burst time

                    priority = int(priority)
                    burst = int(burst)

                    process = Tn, priority, burst

                    Task_list.append(process)
        return Task_list
    except FileNotFoundError:
        msg = "The file " + file + "does not seem to exist."
        print(msg)
        exit(0)
    except ValueError:
        msg = "The file " + file + " does not contain the appropriate content type"
        print(msg)
        exit(0)


def make_dict(Tasks):
    Task_dict = {}                          # dictionary
    for Tn, priority, burst in Tasks:
        Task_dict[Tn] = [priority, burst]   # key = task name, values = priority, burst time

    return Task_dict


def store_bursts(Tasks):
    Task_bursts = {}                        # keep track of burst times
    for Tn, priority, burst in Tasks:
        Task_bursts[Tn] = burst
    return Task_bursts

def turn_around_time_average(ta_time_sum, count_tasks):
    average = ta_time_sum / count_tasks
    print(f"The average turn-around-time is {average}")

def calculate_process_info(ta_time, count_tasks, ta_time_sum, burst):
    ta_time += burst                            # add burst to get turn-around time
    count_tasks += 1                            # note the number of tasks processed
    ta_time_sum += ta_time                      # add turn-around time to total sum

    return ta_time_sum, count_tasks, ta_time    # return these for the next loop

def print_process_info(Tn, burst, ta_time):
    print(f"Process ({Tn}) arrived at time (0) and ran for ({burst}) MS. It had a turn-around time of ({ta_time})") # print info

def waiting_time_sum(wt_sum, ta_time, burst):
    wt_sum += (ta_time - burst) # waiting time is turn around time minus burst time
    return wt_sum

def waiting_time_average(wt_sum, count_tasks):
    average = wt_sum / count_tasks
    print(f"The average waiting-time is {average}")
