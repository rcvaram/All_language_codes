from os import listdir
from os.path import isfile, join
from PIL import Image
import cv2
import os

def get_list_of_images(path):
    return  [f for f in listdir(path) if isfile(join(path, f))]

def variance_of_laplacian(image):
    return cv2.Laplacian(image, cv2.CV_64F).var()


path_name = r"<directory>" # directory where images are stored
image_array = get_list_of_images(path_name)

for item in image_array:
    print("compressing...", item)
    try:        
        image = Image.open(path_name + item)
        new_image = image.resize((1024, 768), Image.ANTIALIAS)         
        new_image.save(path_name + "/" + item, "JPEG", optimize=True, quality=30)
    except:
        print("failed to compress...", item)  
    print("Done!")
