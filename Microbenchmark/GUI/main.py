import csv
import matplotlib.pyplot as plt
import numpy as np
import platform,socket,re,uuid,json,psutil,logging
import multiprocessing
#import numpy as np
import PySimpleGUI as main_window
import PySimpleGUI as new_window
import PySimpleGUI as new_window2
import PySimpleGUI as new_window3

#Mem alloc
avg_static_alloc_c = 0.0
avg_static_alloc_cpp = 0.0

avg_dynamic_alloc_c = 0.0
avg_dynamic_alloc_cpp = 0.0
avg_dynamic_alloc_java = 0.0

#Thread creation
avg_creation_c = 0.0
avg_creation_cpp = 0.0
avg_creation_java = 0.0

#Multiple Threads comparison
avg_creation_c_2 = 0.0
avg_creation_c_4 = 0.0
avg_creation_c_8 = 0.0
avg_creation_c_16 = 0.0
avg_creation_c_32 = 0.0
avg_creation_c_64 = 0.0

avg_creation_cpp_2 = 0.0
avg_creation_cpp_4 = 0.0
avg_creation_cpp_8 = 0.0
avg_creation_cpp_16 = 0.0
avg_creation_cpp_32 = 0.0
avg_creation_cpp_64 = 0.0

avg_creation_java_2 = 0.0
avg_creation_java_4 = 0.0
avg_creation_java_8 = 0.0
avg_creation_java_16 = 0.0
avg_creation_java_32 = 0.0
avg_creation_java_64 = 0.0

avg_switch_c_2 = 0.0
avg_switch_c_4 = 0.0
avg_switch_c_8 = 0.0
avg_switch_c_16 = 0.0
avg_switch_c_32 = 0.0
avg_switch_c_64 = 0.0

avg_switch_cpp_2 = 0.0
avg_switch_cpp_4 = 0.0
avg_switch_cpp_8 = 0.0
avg_switch_cpp_16 = 0.0
avg_switch_cpp_32 = 0.0
avg_switch_cpp_64 = 0.0

avg_switch_java_2 = 0.0
avg_switch_java_4 = 0.0
avg_switch_java_8 = 0.0
avg_switch_java_16 = 0.0
avg_switch_java_32 = 0.0
avg_switch_java_64 = 0.0

def read_c_cpp_file(file_name):
    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=' ')
        for row in csv_reader:
            avg_time.append(float(row[0]))

def read_java_file(file_name):
    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=' ')
        for row in csv_reader:
            avg_time.append(float(row[0]))

def read_file_multiple(file_name):
    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=' ')
        for row in csv_reader:
            avg_time_multiple.append(float(row[0]))

main_window.theme('DarkBlue4')
new_window.theme('DarkBlue4')
layout = [[main_window.Text("platform: " + platform.system())],
          [main_window.Text("platform - release: " + platform.release())],
          [main_window.Text('platform-version: ' + platform.version())],
          [main_window.Text('architecture: ' + platform.machine())],
          [main_window.Text('hostname: ' + socket.gethostname())],
          [main_window.Text('ip-address:'  + socket.gethostbyname(socket.gethostname()))],
          [main_window.Text('mac-address: ' + ':'.join(re.findall('..', '%012x' % uuid.getnode())))],
          [main_window.Text('processor: ' + platform.processor())],
          [main_window.Text('ram: ' + str(round(psutil.virtual_memory().total / (1024.0 **3))) +" GB")],
          [main_window.Text("cores: " + str(multiprocessing.cpu_count()))],
          [main_window.Button("Thread Management")], [main_window.Button("Multiple Threads Comparison")], [main_window.Button("Memory Allocation")],
          [main_window.Button("Close")]]
window = main_window.Window(title="Microbenchmark", size=(450,400),layout = layout)

while True:
    event, values = window.read()
    if event == main_window.WIN_CLOSED or event == "Close":
        break

    if event == "Thread Management":
        newButtons1 = [[new_window.Button("Thread Creation")], [new_window.Button("Thread Context Switch")], [new_window.Button("Close")]]
        win = new_window.Window(title="Thread Management", size=(300, 140), layout=newButtons1)

        while True:
            ev, val = win.read()
            if ev == new_window.WIN_CLOSED or ev == "Close":
                win.close()
                break

            if ev == "Thread Creation":
                avg_time = []
                read_c_cpp_file("th_create_c_1.csv")
                avg_creation_c = avg_time[0]

                avg_time = []
                read_c_cpp_file("th_create_cpp_1.csv")
                avg_creation_cpp = avg_time[0]

                avg_time = []
                read_java_file("th_create_java_1.csv")
                avg_creation_java = avg_time[0]

                names = ["C", "C++", "Java"]
                values = [avg_creation_c, avg_creation_cpp, avg_creation_java]
                y_pos = np.arange(len(names))
                plt.bar(y_pos, values, align='center', alpha=0.5)
                plt.xticks(y_pos, names)
                plt.ylabel('Times in sec')
                plt.title('Thread  Creations Comparison')
                plt.show()

            if ev == "Thread Context Switch":
                avg_time = []
                read_c_cpp_file("th_switch_c_2.csv")
                avg_switch_c_2 = avg_time[0]

                avg_time = []
                read_c_cpp_file("th_switch_cpp_2.csv")
                avg_switch_cpp_2 = avg_time[0]

                avg_time = []
                read_java_file("th_switch_java_2.csv")
                avg_switch_java_2 = avg_time[0]

                names = ["C", "C++", "Java"]
                values = [avg_switch_c_2, avg_switch_cpp_2, avg_switch_java_2]
                y_pos = np.arange(len(names))
                plt.bar(y_pos, values, align='center', alpha=0.5)
                plt.xticks(y_pos, names)
                plt.ylabel('Times in sec')
                plt.title('Thread Context Switch Comparison')
                plt.show()

    if event == 'Memory Allocation':
        newButtons2 = [[new_window.Button("Static")], [new_window.Button("Dynamic")], [new_window.Button("Close")]]
        win1 = new_window.Window(title="Memory Allocation", size=(300, 140), layout=newButtons2)

        while True:
            ev, val = win1.read()
            if ev == new_window.WIN_CLOSED or ev == "Close":
                win1.close()
                break

            if ev == "Static":
                avg_time = []
                read_c_cpp_file("alloc_static_c.csv")
                avg_static_alloc_c = avg_time[0]

                avg_time = []
                read_c_cpp_file("alloc_static_cpp.csv")
                avg_static_alloc_cpp = avg_time[0]

                names = ["C", "C++"]
                values = [avg_static_alloc_c, avg_static_alloc_cpp]
                y_pos = np.arange(len(names))
                plt.bar(y_pos, values, align='center', alpha=0.5)
                plt.xticks(y_pos, names)
                plt.ylabel('Times in sec')
                plt.title('Static Memory Allocation Comparison')
                plt.show()

            if ev == "Dynamic":
                avg_time = []
                read_c_cpp_file("alloc_dynamic_c.csv")
                avg_dynamic_alloc_c = avg_time[0]

                avg_time = []
                read_c_cpp_file("alloc_dynamic_cpp.csv")
                avg_dynamic_alloc_cpp = avg_time[0]

                avg_time = []
                read_java_file("alloc_dynamic_java.csv")
                avg_dynamic_alloc_java = avg_time[0]

                names = ["C", "C++", "Java"]
                values = [avg_dynamic_alloc_c, avg_dynamic_alloc_cpp, avg_dynamic_alloc_java]
                y_pos = np.arange(len(names))
                plt.bar(y_pos, values, align='center', alpha=0.5)
                plt.xticks(y_pos, names)
                plt.ylabel('Times in sec')
                plt.title('Dynamic Memory Allocation Comparison')
                plt.show()


    if event == "Multiple Threads Comparison":
        newButtons3 = [[new_window.Button("Thread Creation")], [new_window.Button("Thread Context Switch")], [new_window.Button("Close")]]
        win2 = new_window.Window(title="Multiple Threads Comparison", size=(300, 140), layout=newButtons3)

        while True:
            ev, val = win2.read()
            if ev == new_window.WIN_CLOSED or ev == "Close":
                win2.close()
                break

            if ev == "Thread Creation":
                layout2 = [[new_window2.Button("C"), new_window2.Button("C++")],
                           [new_window2.Button("Java")], [new_window.Button("Close")]]
                win3 = new_window2.Window(title="Thread Creation", size=(300, 140), layout=layout2)

                while True:
                    e, v = win3.read()

                    if e == new_window2.WIN_CLOSED or e == "Close":
                        win3.close()
                        break

                    if e == "C":
                        avg_time_multiple = []
                        read_file_multiple("th_create_c_1.csv")
                        avg_creation_c = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_2.csv")
                        avg_creation_c_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_4.csv")
                        avg_creation_c_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_8.csv")
                        avg_creation_c_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_16.csv")
                        avg_creation_c_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_32.csv")
                        avg_creation_c_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_c_64.csv")
                        avg_creation_c_64 = avg_time_multiple[0]

                        names = ["1 Th", "2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_creation_c, avg_creation_c_2, avg_creation_c_4, avg_creation_c_8, avg_creation_c_16, avg_creation_c_32, avg_creation_c_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Creation')
                        plt.show()

                    if e == "C++":
                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_1.csv")
                        avg_creation_cpp = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_2.csv")
                        avg_creation_cpp_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_4.csv")
                        avg_creation_cpp_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_8.csv")
                        avg_creation_cpp_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_16.csv")
                        avg_creation_cpp_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_32.csv")
                        avg_creation_cpp_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_cpp_64.csv")
                        avg_creation_cpp_64 = avg_time_multiple[0]

                        names = ["1 Th", "2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_creation_cpp, avg_creation_cpp_2, avg_creation_cpp_4, avg_creation_cpp_8, avg_creation_cpp_16, avg_creation_cpp_32, avg_creation_cpp_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Creation')
                        plt.show()

                    if e == "Java":
                        avg_time_multiple = []
                        read_file_multiple("th_create_java_1.csv")
                        avg_creation_java = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_2.csv")
                        avg_creation_java_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_4.csv")
                        avg_creation_java_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_8.csv")
                        avg_creation_java_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_16.csv")
                        avg_creation_java_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_32.csv")
                        avg_creation_java_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_create_java_64.csv")
                        avg_creation_java_64 = avg_time_multiple[0]

                        names = ["1 Th", "2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_creation_java, avg_creation_java_2, avg_creation_java_4, avg_creation_java_8,
                                  avg_creation_java_16, avg_creation_java_32, avg_creation_java_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Creation')
                        plt.show()

            if ev == "Thread Context Switch":
                layout3 = [[new_window2.Button("C"), new_window2.Button("C++")],
                           [new_window2.Button("Java")], [new_window.Button("Close")]]
                win4 = new_window2.Window(title="Thread Context Switch", size=(300, 140), layout=layout3)

                while True:
                    e, v = win4.read()

                    if e == new_window2.WIN_CLOSED or e == "Close":
                        win4.close()
                        break

                    if e == "C":
                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_2.csv")
                        avg_switch_c_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_4.csv")
                        avg_switch_c_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_8.csv")
                        avg_switch_c_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_16.csv")
                        avg_switch_c_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_32.csv")
                        avg_switch_c_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_c_64.csv")
                        avg_switch_c_64 = avg_time_multiple[0]

                        names = ["2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_switch_c_2, avg_switch_c_4, avg_switch_c_8,
                                  avg_switch_c_16, avg_switch_c_32, avg_switch_c_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Context Switch')
                        plt.show()

                    if e == "C++":
                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_2.csv")
                        avg_switch_cpp_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_4.csv")
                        avg_switch_cpp_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_8.csv")
                        avg_switch_cpp_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_16.csv")
                        avg_switch_cpp_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_32.csv")
                        avg_switch_cpp_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_cpp_64.csv")
                        avg_switch_cpp_64 = avg_time_multiple[0]

                        names = ["2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_switch_cpp_2, avg_switch_cpp_4, avg_switch_cpp_8,
                                  avg_switch_cpp_16, avg_switch_cpp_32, avg_switch_cpp_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Context Switch')
                        plt.show()

                    if e == "Java":
                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_2.csv")
                        avg_switch_java_2 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_4.csv")
                        avg_switch_java_4 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_8.csv")
                        avg_switch_java_8 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_16.csv")
                        avg_switch_java_16 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_32.csv")
                        avg_switch_java_32 = avg_time_multiple[0]

                        avg_time_multiple = []
                        read_file_multiple("th_switch_java_64.csv")
                        avg_switch_java_64 = avg_time_multiple[0]

                        names = ["2 Th", "4 Th", "8 Th", "16 Th", "32 Th", "64 Th"]
                        values = [avg_switch_java_2, avg_switch_java_4, avg_switch_java_8,
                                  avg_switch_java_16, avg_switch_java_32, avg_switch_java_64]
                        y_pos = np.arange(len(names))
                        plt.bar(y_pos, values, align='center', alpha=0.5)
                        plt.xticks(y_pos, names)
                        plt.ylabel('Times in sec')
                        plt.title('Multiple Threads Context Switch')
                        plt.show()
window.close()