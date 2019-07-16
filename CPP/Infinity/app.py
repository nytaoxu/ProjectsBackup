import enum


class BugStatus(enum.Enum):
    new = 7
    invalid = 5


print(f"new = {BugStatus.new.value}")
print(f"new = {BugStatus.invalid.name}")

for status in BugStatus:
    print(f"{status} - {status.name} - {status.value}")
