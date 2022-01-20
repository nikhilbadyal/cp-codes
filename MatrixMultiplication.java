package algorithmdesign.dynamic.rodcut;

public class MatrixMultiplication {
    public static void main(String[] args) {
        int p = 3 ;
        int q =  3 ;
        int r = 3;
        int[][] mat1 = new  int[p][q];
        int[][] mat2 = new  int[q][r];
       int[][] mat3 = new  int[p][r];

        for(int i = 0 ; i < mat1.length ; ++i){
            for(int j = 0 ; j < mat2[0].length ; ++j){
                mat1[i][j] = mat2[i][j] =  3 ;
            }
        }

        System.out.println("Matrix 1 ");
        for(int i = 0 ; i < mat1.length ; ++i){
            for(int j = 0 ; j < mat2[0].length ; ++j){
                System.out.print(mat1[i][j]+ "  ");
            }
            System.out.println("\n");
        }

        System.out.println("Matrix 2 ");
        for(int i = 0 ; i < mat1.length ; ++i){
            for(int j = 0 ; j < mat2[0].length ; ++j){
                System.out.print(mat2[i][j]+ "  ");
            }
            System.out.println("\n");
        }
       try{
           multiply(mat1,mat2,mat3);
       } catch (IllegalStateException e) {
           System.out.println(e.getMessage());
       }
        for(int i = 0 ; i < mat1.length ; ++i){
            for(int j = 0 ; j < mat2[0].length ; ++j){
                System.out.print(mat3[i][j]+ "  ");
            }
            System.out.println("\n");
        }
    }

    private static void multiply(int[][] mat1, int[][] mat2,int[][] mat3) {
        if(mat1[0].length != mat2.length){
            throw new IllegalStateException("Dimensions not compatible.");
        }
        for(int i = 0 ; i < mat1.length ; ++i){
            for(int j = 0  ; j < mat2[0].length ; ++j){
                mat3[i][j] = 0 ;
                for(int  k = 0 ; k < mat2[0].length ; ++k){
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }


    }
}
