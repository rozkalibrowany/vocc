from PIL import Image
import os

COLOR_OFFSET = 57

def value_to_rgb(value):
    r = 0
    g = 0
    b = 0

    value = value + COLOR_OFFSET
    if value > 255:
        value = 255

    if value <= 127:
        r = value*2
        g = 255
    else:
        r = 255
        g = (255 - value)*2

    return (r,g,b)

def get_images(imageDir):
    files = os.listdir(imageDir)
    images = []

    for file in files:
        filePath = os.path.abspath(os.path.join(imageDir, file))
        try:
            fp = open(filePath, 'rb')
            im = Image.open(fp)
            images.append(im)
            im.load()
            fp.close()
        except:
            print("Nieprawidłowy obraz: %s" % (filePath,))

    return images

def colorize(images):

    step = int(255/len(images))
    value = 0
    
    for index, image in enumerate(images):
        print("Processing " + str(index+1) + ". image")
        pixels = image.load()
        width, height = image.size
        for x in range(width):
            for y in range(height):
                r, g, b, a = pixels[x, y]
                R_NEW, G_NEW, B_NEW = value_to_rgb(value)
                if (r, g, b) != (R_NEW, G_NEW, B_NEW):
                    pixels[x, y] = (R_NEW, G_NEW, B_NEW, a)
        image.save("colorized_circles/circle" + str(index+1) + ".png", "PNG")
        value += step



####
images = get_images('circles')
colorize(images)
print("Done")
