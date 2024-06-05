import subprocess

import pprint

POD_NAME = "pod_name"
READY = "ready"
STATUS = "status"
RESTARTS = "restarts"
AGE = "age"

def parse_pod_status(output):
    """Parse the output of 'kubectl get pods' command into a dictionary."""
    pods = {}
    lines = output.split('\n')[1:]  # Skip the header line
    for line in lines:
        if line.strip():  # Skip empty lines
            parts = line.split()
            name = parts[0]
            ready = parts[1]
            status = parts[2]
            restarts = parts[3]
            age = parts[4]
            pods[name] = {
                'ready': ready,
                'status': status,
                'restarts': restarts,
                'age': age
            }

    print(pods)

    final_data = []

    for data in pods:
        final_data.append({POD_NAME: data, 
                           READY: pods[data][READY],
                           STATUS: pods[data][STATUS],
                           RESTARTS: pods[data][RESTARTS],
                           AGE: pods[data][AGE]})

    # Name ready status restart age            
    return final_data


def setup_environment():
    """Set up the environment variables."""
    commands = [
        "cd /home/omesharm/",
        "source ~/.bashrc",
        "cd .kube/",
        "source OKE1_SOURCEME"
    ]
    for command in commands:
        subprocess.run(command, shell=True, check=True)

def conveyMsg(msg):
    pprint.pprint(msg)

def execute_command(command):
    """Execute a shell command and return the output."""
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    return result.stdout.decode('utf-8')

def get_pods(namespace):
    """Fetch the number of pods in the specified namespace."""
    #command = f'kubectl get pods -n {namespace} | grep -v NAME | wc -l'
    command = f'kubectl get pods -n {namespace}'
    output = execute_command(command)
    conveyMsg(f'Running command {command}')
    conveyMsg(f'get result {command}')
    return output

def deletePod(namespace, pod_details):

    #conveyMsg("Enter pod name starts with: ")
    pod_name_hint = input("Enter pod name starts with: ")

    found_pod = ""
    for p_details in pod_details:
        if p_details[POD_NAME].startswith(pod_name_hint):
            found_pod = p_details[POD_NAME]
            break
        
    if found_pod:

        command = f'kubectl -n {namespace} delete pod {found_pod}'
        output = command
        #output = execute_command(command)
        #conveyMsg(f'Running command {command}')
        #conveyMsg(f'get result {command}')
        return output
    else:
        conveyMsg("Pod Name is not valid.. Exiting")

        return False

if __name__ == "__main__":
    # Replace 'your-namespace' with the desired namespace name
    namespace = input("Enter the namespace name: ")
    pods_detail = get_pods(namespace)
    pods_detail = parse_pod_status(pods_detail)

    #conveyMsg(pods_detail)

    d_pod_result = deletePod(namespace, pods_detail)
    print(d_pod_result)
