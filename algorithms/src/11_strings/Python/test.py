m = [1, 2, 3, 4, 5]
img = [m[:] for _ in range(5)]
print(img)
img[0][0] = 111
print(img)