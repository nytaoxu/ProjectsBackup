help_info = """
start - start the car
 stop - stop the car
 quit - quit the program
"""
# stopped, started
current_status = "stopped"

while True:
    command = input("> ").lower()
    if command == "help":
        print(help_info)
    elif command == "start":
        if current_status == "stopped":
            print("Car started.")
            current_status = "started"
        else:
            print("Car is already started.")
    elif command == "stop":
        if current_status == "started":
            print("Car stopped.")
            current_status = "stopped"
        else:
            print("Car is already stopped.")
    elif command == "quit":
        current_status = "stopped"
        print("You have successfully quit the program.")
        break
    else:
        print("I don't understand that command.")
