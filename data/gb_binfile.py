from numpy import dtype, int64, byte, memmap
DEFAULT_HEADER_DTYPE = dtype([('rows', int64), ('dimensions', int64), ('bytes_per_axis', int64)])


def make_binfile(filename, header_dtype, data_dtype, num_data_elems=10 ** 5):
    """
    Create a binary file and then create a GBBinFile that sits on top of it
    -------------------
    Make an empty binary file containing an initial header of dtype=header_dtype and
    followed by a data section containing num_data_elems elements of dtype=data_dtype
    """
    filesize = header_dtype.itemsize + num_data_elems * data_dtype.itemsize
    arr = memmap(filename, mode='w+', dtype=byte, shape=(filesize,))
    arr.flush()
    return GBBinFile(filename, header_dtype, data_dtype)


class GBBinFile(object):
    """
    Class that sits on top of an existing binary file created via make_binfile.
    This class creates views of the header and data section and hence makes access
    to the binary data more convenient.
    """
    def __init__(self, filename, header_dtype, data_dtype):
        self.filename = filename
        self.header_dtype = header_dtype
        self.data_dtype = data_dtype
        self._mmap = memmap(self.filename, mode='r+', dtype=byte, offset=0)
        self.header = self._mmap[:header_dtype.itemsize].view(dtype=header_dtype)
        self.data = self._mmap[header_dtype.itemsize:].view(dtype=data_dtype)
