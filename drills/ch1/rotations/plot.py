import matplotlib.pyplot as plt
import numpy as np

# Recall that `j` in Python represents the imaginary number `i`

# Plot constants
amountRotate = 3
numPoints = 7
startPoint = 0
pointColor = 'red'

fig, axis = plt.subplots(1)

orig = np.arange(numPoints) + 1j * np.arange(startPoint, startPoint+numPoints)
X = [x.real for x in orig]
Y = [x.imag for x in orig]
axis.scatter(X, Y, color=pointColor, alpha=0.25, label='Original')

rotated = orig * amountRotate
X_r = [x.real for x in rotated]
Y_r = [y.imag for y in rotated]
axis.scatter(X_r, Y_r, color=pointColor, alpha=1.0, label='Rotated')

# Legend for original and rotated points
plt.legend(loc="upper left", framealpha=1.0, ncol=2)

# Draw x-axis and y-axis through the origin
plt.axhline(0, color='gray')
plt.axvline(0, color='gray')

# Equal-spaced grids
plt.gca().set_aspect("equal")
plt.grid(axis='both', linestyle='--', color='gray', alpha=0.25)

plt.title('Rotating ' + str(numPoints) + ' complex points by ' + str(amountRotate))
fig.tight_layout()

filename = 'plot.png'
plt.savefig(filename, bbox_inches='tight')
print('Plot saved to %s' % filename)

plt.show()
