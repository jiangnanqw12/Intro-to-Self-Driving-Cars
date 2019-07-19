import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1.0
        return I
def transpose(matrix):
    row=len(matrix)
    col=len(matrix[0])
    matrix_transpose = []
    for i in range(col):
        row_data=[]
        for j in range(row):
            row_data.append(matrix[j][i])#matrix_transpose[i][j]
        matrix_transpose.append(row_data)
    #print(matrix_transpose)
    return matrix_transpose
def dot_product(vector_one, vector_two):
    vector_dot=0
    for i in range(len(vector_one)):
        vector_dot+=(vector_one[i]*vector_two[i])
    return vector_dot

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])
        #self.d =0
        #self.t =0

    #
    # Primary matrix math methods
    #############################
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
        
        # TODO - your code here
        elif self.h==2:
            determinant=self.g[0][0]*self.g[1][1]-self.g[1][0]*self.g[0][1]
        elif self.h==1:
            determinant=self.g[0][0]
        self.d=determinant
    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate the trace of a non-square matrix.")

        # TODO - your code here
        trace=0
        for i in range(self.h):
            trace+=self.g[i][i]
        self.t=trace
    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")

        # TODO - your code here
        elif self.h==2:
            a=self.g[0][0]
            b=self.g[0][1]
            c=self.g[1][0]
            d=self.g[1][1]
            if self.d==0:
                raise ValueError('The matrix is a non-invertible')
            matrix_inverse=self.g
            matrix_inverse[0][0]=d/delta
            matrix_inverse[0][1]=-b/delta
            matrix_inverse[1][0]=-c/delta
            matrix_inverse[1][1]=a/delta
            
        elif self.h==1:
            
            matrix_inverse=[[1/self.g[0][0]]]
        return Matrix(matrix_inverse)
    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        # TODO - your code here
        matrix_transposed=[]
        for i in self.w:
            row=[]
            for j in self.h:
                row.append(self.g[i][j])
                #matrix_transposed[i][j]=self.g[j][j]
            matrix_transposed.append(row)
        return Matrix(matrix_transposed)
    def is_square(self):
        return self.h == self.w

    #
    # Begin Operator Overloading
    ############################
    def __getitem__(self,idx):
        """
        Defines the behavior of using square brackets [] on instances
        of this class.

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > my_matrix[0]
          [1, 2]

        > my_matrix[0][0]
          1
        """
        return self.g[idx]

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
        #   
        # TODO - your code here
        #
        Matrix_sum=self.g
        for r in range(self.h):
            for c in range(self.w):
                Matrix_sum[r][c]=self.g[r][c]+other.g[r][c]
        return Matrix(Matrix_sum)

    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        #   
        # TODO - your code here
        #
        #Matrix_neg=self.g
        Matrix_neg=[]
        #print('test_neg',self.g)
        for i in range(self.h):
            row=[]
            for j in range(self.w):
                row.append(-self.g[i][j])
            Matrix_neg.append(row)
                #Matrix_neg[i][j]=-Matrix_neg[i][j]
        #print('test_neg2',self.g)        
        return Matrix(Matrix_neg)
    
    
    def __sub__(self, other):
        """
        Defines the behavior of - operator (as subtraction)
        """
        #   
        # TODO - your code here
        #
        return Matrix(self.g)+(-Matrix(other.g))
    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        #   
        # TODO - your code here
        #
        Matrix_mul=[]
        for i in range(self.h):
            row=[]
            for j in range(other.w):
                row.append(dot_product(self.g[i],transpose(other.g)[j]))
            Matrix_mul.append(row)
                           
        return Matrix(Matrix_mul)
                           
    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
              
        if isinstance(other, numbers.Number):
            
            #   
            # TODO - your code here
            #
                           
            Matrix_rmul=self.g
            for i in range(self.h):
                          
                for j in range(self.w):
                    Matrix_rmul[i][j]*=other
                           
        
        return Matrix(Matrix_rmul)
                    
                           
                    
                           
                           
            
            