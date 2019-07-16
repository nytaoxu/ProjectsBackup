# import array


class Hotel:
    def __init__(self, name, location):
        self.name = name
        self.location = location
        self.occupiedCnt = 0
        self.numOfRooms = 0
        self.theRooms = []
        self.addRoom(self, 101, "king", "not smoking", 65.0)
        self.addRoom(self, 102, "king", "not smoking", 65.0)
        self.addRoom(self, 103, "king", "not smoking", 65.0)
        self.addRoom(self, 104, "king", "not smoking", 65.0)
        self.addRoom(self, 105, "king", "not smoking", 65.0)
        self.addRoom(self, 106, "king", "not smoking", 65.0)
        self.addRoom(self, 107, "king", "not smoking", 65.0)
        self.addRoom(self, 108, "king", "not smoking", 65.0)
        self.addRoom(self, 109, "king", "not smoking", 65.0)
        self.addRoom(self, 110, "king", "not smoking", 65.0)

    def isFull(self):
        return len(self.theRooms) == self.occupiedCnt

    def isEmpty(self):
        return self.occupiedCnt == 0

    def addRoom(self, roomnumber, bedtype, smoking, price):
        room = Room(roomnumber, bedtype, smoking, price)
        self.theRooms.append(room)
        self.numOfRooms += 1

    def addReservation(self, occupantName, smoking, bedType):
        for r in self.theRooms:
            if not r.occupied and r.smoking == smoking and r.bedType == bedType:
                r.occupied = True
                r.occupant = occupantName
                self.occupiedCnt += 1
                print(f"Guest {occupantName} gets Room {r.roomNum} that meets all his/her requirements.")
                break
        else:
            print(f"No room available that meets guest {occupant}'s requirements.")

    def cancelReservation(self, occupantName):
        response = self.findReservation(self, occupantName)
        if response == "NOT_FOUND":
            print(f"No reservation is found for guest {occupantName}.")
        else:
            for room in self.theRooms:
                if room.roomNum == response:
                    room.occupied = False
                    room.occupant = None
                    self.occupiedCnt -= 1
                    print(f"The reservation for guest {occupantName} in Room {r.roomNum} has successfully cancelled.")
                    break
            else:
                print(f"No reservation is found for guest {occupantName}.")

    def findReservation(self, occupantName):
        for r in self.theRooms:
            if r.occupied and r.occupant == occupantName:
                return r.roomNum
        else:
            return "NOT_FOUND"

    def printReservationList(self):
        for r in self.theRooms:
            if r.occupied:
                smoking_string = 'y' if r.smoking == 'smoking' else 'n'
                print(f"Room Number: {r.roomNum}\n Occupant name: {r.occupant}\nSmoking room: {smoking_string}\nBed Type: {r.bedType}\n Rate: {r.rate}\n")

    def getDailySales(self):
        dailySales = 0
        for r in self.theRooms:
            if r.occupied:
                dailySales += r.rate
        return dailySales

    def occupancyPercentage(self):
        return self.occupiedCnt / len(self.theRooms)

    def __str__(self):
        print(f"Hotel Name : {self.name}\n Number of Rooms : {len(self.theRooms)}\n Number of Occupied Rooms : {self.occupiedCnt}\n")
        for r in self.theRooms:
            print(f"Room Number: {r.roomNum}")
            print(f"Occupant Name: {r.occupant if r.occupied else 'Not Occupied'}")
            print(f"Smoking room: {r.smoking[0]}")
            print(f"Bed Type: {r.bedType}")
            print(f"Rate: {r.rate}")

    def setName(self, name):
        self.name = name

    def setLocation(self, location):
        self.location = location

    def getName(self):
        return self.name

    def getLocation(self):
        return self.location


class Room:
    def __init__(self, roomNum, bedType, smoking, rate):
        self.roomNum = roomNum
        self.bedType = bedType
        self.smoking = smoking
        self.rate = rate
        self.occupied = False
        self.occupant = None

    def getBedType(self):
        return self.bedType

    def getSmoking(self):
        return self.smoking

    def getRoomNum(self):
        return self.roomNum

    def getRoomRate(self):
        return self.rate

    def getOccupant(self):
        return self.occupant

    def setOccupied(self, occupied):
        self.occupied = occupied

    def setOccupant(self, occupant):
        self.occupant = occupant

    def setRoomNum(self, roomNum):
        self.roomNum = roomNum

    def setBedType(self, bedType):
        self.bedType = bedType

    def setRate(self, rate):
        self.rate = rate

    def setSmoking(self, smoking):  # string
        self.smoking = smoking

    def isOccupied(self):
        return self.occupied

    def __str__(self):
        occupied_string = f"occupied, and the occupant is {self.getOccupant()}" if self.isOccupied() else "not occupied"
        return f"""
        The room number is {self.getRoomNum()}, it is {occupied_string},
        the bed type is {self.getBedType()}, it is listed as {self.getSmoking()},
        and its rental rate is {self.getRoomRate()} per day.
        """
