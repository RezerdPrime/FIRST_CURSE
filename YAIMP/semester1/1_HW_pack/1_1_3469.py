time = int(input())

hours = (time // 3600) % 24; time -= (time // 3600) * 3600
minutes = time // 60; seconds = time % 60

print(str(hours), str(minutes).zfill(2), str(seconds).zfill(2), sep = ":")
