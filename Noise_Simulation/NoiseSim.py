import numpy as np
import matplotlib.pyplot as plt


'''

Author: Emmanouil Raptakis

The purpose of this code is to statistically discover the nature of IEEE rounding
through the creation of an array through utilising rounding errors.
'''

def main(length):

    """
    Generates a random numpy array using rounding from IEEE 64 -> 32 bit
    rounding.

    Inputs:
        length

    Returns:
        random array
    """

    floatarray = np.random.sample(length)

    intarray = np.array(np.random.sample(length)*100,dtype=np.int8) #multiply by 100 to 'act' as if we are casting float -> int

    #use an irrational number ( sqrt(2) ) to create an inexpressible result in floats
    array_32 = np.array(intarray, dtype = np.float32)/np.sqrt(2)
    array_64 = np.array(intarray, dtype = np.float64)/np.sqrt(2)

    #finds the difference between the two arrays
    diff = array_32 - array_64

    #finds the absolute difference between the arrays
    diff_abs = np.abs(diff)

    #take the natural log to fit the data more nicely (must be abs -> ln to avoid NaN)
    diff_ln = np.log(diff_abs)

    plt.hist(diff, bins = 'auto')
    plt.show()
    '''
    noise = diff * 5 * 10**4
    x = np.linspace(0,2*np.pi,length)
    y1 = np.sin(x)
    y1 += noise #addition of noise

    y2 = np.sin(x)
    y2 += floatarray/2

    plt.plot(x,y1)

    plt.figure()
    plt.plot(x,y2)
    plt.show()
    '''

main(1000000000)
