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
    blackout = 0
    transparency = 180
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

                R_NEW = R_NEW - blackout if R_NEW >= blackout else 0
                G_NEW = G_NEW - blackout if G_NEW >= blackout else 0
                B_NEW = B_NEW - blackout if B_NEW >= blackout else 0
                a = a - transparency if a >= transparency else 0
                
                if (r, g, b) != (R_NEW, G_NEW, B_NEW):
                    pixels[x, y] = (R_NEW, G_NEW, B_NEW, a)
        image.save("dark_colorized_circles/circle" + str(index+1) + ".png", "PNG")
        value += step



####
images = get_images('circles')
colorize(images)
print("Done")
