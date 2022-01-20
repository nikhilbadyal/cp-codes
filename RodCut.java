package algorithmdesign.dynamic.rodcut;

public class RodCut {
    public static void main(String[] args) {
        int[][] pricechart = new int[2][10];

        for(int  i = 0 ; i < 10 ; ++i){
            pricechart[0][i] = i+1;
        }
        pricechart[1][0] =  1 ;
        pricechart[1][1] = 5;
        pricechart[1][2] = 8;
        pricechart[1][3]  = 9;
        pricechart[1][4] = 10;
        pricechart[1][5] = 17;
        pricechart[1][6] = 17;
        pricechart[1][7] = 20;
        pricechart[1][8] = 24;
        pricechart[1][9] = 30;

       /* for(int i = 0  ; i < 10 ; ++i){
            System.out.print(pricechart[0][i]+ "  ");
        }
        System.out.println("\n");
        for(int i = 0  ; i < 10 ; ++i){
            System.out.print(pricechart[1][i]+ "  ");
        }*/
        int size = 10;
        int price;
        int price1;
        int price2 ;
        int [] solution = new int[size+1];
        try{
            price = cutrod(pricechart , size);
            price1 = cutrodDynamic(pricechart,size);
            price2 = cutrodDynamicBottomUp(pricechart,size);
            int price3 = extended(pricechart, size, solution);
            String constString = " is the profit price.";
           System.out.println(price+constString);
            System.out.println(price1+constString);
            System.out.println(price2+constString);
            System.out.println(price3+constString);
            for (int value : solution) {
                System.out.print(value + "  ");
            }
        }catch (IllegalArgumentException err){
            System.out.println(err.getMessage());
        }
    }

    private static int extended(int[][] pricechart, int size,int[] solution) {
        int []table = new int[size+1];
        table[0] = 0;
        for(int i = 1 ; i <= size ; ++i) {
            int q = Integer.MIN_VALUE;
            for(int j = 1 ; j <= i ; ++j){
                if(q < pricechart[1][j-1] + table[i -j]){
                    q = pricechart[1][j-1] + table[i-j];
                    solution[i] = j;
                }
            }
            table[i] = q;
        }
        return table[size];
    }
    private static int cutrodDynamicBottomUp(int[][] pricechart, int size) {
        int[] table = new int[size+1];
        table[0] = 0;
        for(int i = 1 ; i <= size ; ++i){
            int q = Integer.MIN_VALUE;
            for(int j = 1 ; j <= i ; ++j){ //2
                q = Math.max(q,pricechart[1][j-1]+table[i-j]);
            }
            table[i]  = q   ;
        }
        return  table[size];
    }

    private static int cutrodDynamic(int[][] pricechart, int size) {
        int [] table = new int[size+1];
        for(int  i = 0 ; i < size ; ++i){
            table[i] = Integer.MIN_VALUE;
        }
        return cutrodDynamicAux(pricechart,size,table);
    }

    private static int cutrodDynamicAux(int[][] pricechart, int size, int[] table) {
       if(table[size]>0){
            return  table[size];
        }
        int q ;
        if(size  == 0){
            q = 0 ;
        }else{
            q = Integer.MIN_VALUE;
            for(int i = 0 ; i < size ; ++i){
                int j = 1 + i;
                q = Math.max(q,pricechart[1][i]+cutrodDynamicAux(pricechart,size-j,table));
            }
        }
        table[size] = q;
        return  q;
    }

    private static int cutrod(int[][] pricechart, int size) {
        if(size > pricechart[0].length){
            throw  new IllegalArgumentException("Enough data not available.");
        }
        if(size == 0){
            return 0;
        }
        int q = Integer.MIN_VALUE;
        for(int i = 0 ; i < size ; ++i){
            int j = 1 + i;
            q = Math.max(q,pricechart[1][i]+cutrod(pricechart,size-j));
        }
        return  q;
    }
}