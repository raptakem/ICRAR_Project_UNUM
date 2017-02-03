from astropy.io import fits
import matplotlib.pyplot as plt


datalist = fits.open('sky.fits') #open the .fits file from skymaker
stars = datalist[0].data


plt.imshow(stars.data)
plt.show()
