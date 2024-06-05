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
    return pods

if __name__ == "__main__":
    # Sample output from 'kubectl get pods' command
    output = """
    NAME                                                              READY   STATUS             RESTARTS   AGE
    batch-wireless-pipe-86b668cb6d-zjbpx                              0/1     ImagePullBackOff   0          25h
    cm-698456f5b5-2lcnm                                               2/2     Running            0          25h
    dm-fusa-77cd77df8d-2m8sl                                          1/1     Running            0          25h
    dm-oracle-77f57d5989-dhkf4                                        1/1     Running            0          25h
    fusa-simulator-84f79c469d-pldx2                                   1/1     Running            0          25h
    init-db-vfzxq                                                     0/1     Completed          0          25h
    lds-config-job-jsrh2                                              0/1     Completed          0          25h
    nfs-subdir-omesharm-dev-nfs-subdir-external-provisioner-56m4h4x   1/1     Running            0          15h
    pje-7cdf6cdb88-gn2qh                                              1/1     Running            0          25h
    realtime-pipe-688dc7bd4f-8q7js                                    1/1     Running            0          24h
    realtime-pipe-ii-6d4d74f8d-q5vjf                                  1/1     Running            0          24h
    rel-daemon-9dd4b4f86-khwnk                                        0/1     ImagePullBackOff   0          25h
    """

    # Parse the output into a dictionary
    pod_status = parse_pod_status(output)
    print("Pod Status:")
    print(pod_status)
