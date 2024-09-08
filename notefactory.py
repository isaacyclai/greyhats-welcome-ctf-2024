import subprocess
import time

command = ["nc", "challs.nusgreyhats.org", "32111"]

process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
output = ""
while("press enter to begin" not in output):
    output = process.stdout.readline()
    print(output)

process.stdin.write('\n')
process.stdin.flush()

while(1):
    output = process.stdout.readline().rstrip()
    if output == "| X |   |   |   |":
        process.stdin.write('h')
        process.stdin.flush()
    elif output == "|   | X |   |   |":
        process.stdin.write('j')
        process.stdin.flush()
    elif output == "|   |   | X |   |":
        process.stdin.write('k')
        process.stdin.flush()
    elif output == "|   |   |   | X |":
        process.stdin.write('l')
        process.stdin.flush()
    else:
        print(output)
        if "flag" in output:
            break