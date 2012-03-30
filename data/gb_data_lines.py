import numpy as np
from numpy import dtype, int64, int16
from gb_binfile import make_binfile
from gb_data_settings import SCREEN_X_RES, SCREEN_Y_RES

POINT_DTYPE = int16
POINT_DTYPE_INSTANCE = dtype([('x', POINT_DTYPE)])
HEADER_DTYPE = dtype([('rows', int64), ('dimensions', int64), ('bytes_per_axis', int64)])
DATA_DTYPE = dtype([('x1', POINT_DTYPE), ('y1', POINT_DTYPE), ('x2', POINT_DTYPE), ('y2', POINT_DTYPE)])


class GBLinesGenerator(object):
    def __init__(self, binfile, screen_width, screen_height, num_data_elems=10 ** 2, header_dtype=HEADER_DTYPE, data_dtype=DATA_DTYPE, dimension=2):
        self.screen_width = screen_width
        self.screen_height = screen_height
        self.num_data_elems = num_data_elems
        self.binfile = binfile
        self.dimension = dimension

    def generate(self):
        start = (np.random.randint(self.screen_width), np.random.randint(self.screen_height))
        self.binfile.header[0][0] = self.num_data_elems
        self.binfile.header[0][1] = self.dimension
        self.binfile.header[0][2] = POINT_DTYPE_INSTANCE.itemsize
        for i in range(self.num_data_elems):
            end = (np.random.randint(self.screen_width), np.random.randint(self.screen_height))
            self.binfile.data[i][0] = start[0]
            self.binfile.data[i][1] = start[1]
            self.binfile.data[i][2] = end[0]
            self.binfile.data[i][3] = end[1]
            start = end


if __name__ == '__main__':
    num_data_elems = 10**2
    binfile = make_binfile('gb_lines.data', HEADER_DTYPE, DATA_DTYPE, num_data_elems=num_data_elems)
    datagen = GBLinesGenerator(binfile, SCREEN_X_RES, SCREEN_Y_RES, num_data_elems=num_data_elems)
    datagen.generate()
