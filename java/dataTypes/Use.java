package dataTypes;

public class Use {
	public static void main(String[] args) {
		try {
			System.out.println("------------------------------------");
			System.out.println("| OPERAZIONI ELEMENTARI SU MATRICI |");
			System.out.println("------------------------------------");
			System.out.println();
			
			//Matrici e operazioni elementari
			Matrix ma = new Matrix(2,3,3,2,1,6,-2,4);
			Matrix mb = new Matrix(2,3,4,1,-1,1,3,7);
			Matrix mc = new Matrix(3,2,3,2,4,5,6,1);
			
			System.out.println("Matrice ma: ");
			System.out.println(ma);
			
			System.out.println("Matrice mb: ");
			System.out.println(mb);
			
			System.out.println("Matrice mc: ");
			System.out.println(mc);
			
			System.out.println("Matrice ma + mb: ");
			System.out.println(ma.add(mb));
			
			System.out.println("Matrice ma - mb: ");
			System.out.println(ma.sub(mb));
			
			System.out.println("Prodotto con lo scalare 3.0 con la matrice ma: ");
			System.out.println(ma.multiply(3.0));
			
			System.out.println("Prodotto scalare tra ma e mc: ");
			System.out.println(ma.multiply(mc));
			
			
			
			System.out.println("---------------------------------------");
			System.out.println("| ALTRE OPERAZIONI E MATRICI QUADRATE |");
			System.out.println("---------------------------------------");
			System.out.println();
			// 2x2
			SquareMatrix m1 = new SquareMatrix(2,2,-3,1,3);
			System.out.print(m1);
			System.out.println("Determinante: " + m1.determinant() + "\n");
			
			// 3x3
			SquareMatrix m2 = new SquareMatrix(3, 0, 2, -3, 0, 1, 3, 2, 0, -1);
			System.out.print(m2);
			System.out.println("Determinante: " + m2.determinant() + "\n");
			
			SquareMatrix r2ridotta = m2.getMinor(0, 1);
			System.out.println(r2ridotta);
			
			//5x5
			SquareMatrix m3 = new SquareMatrix(5,
					0,0,0,1,2,
					1,3,2,-1,0,
					4,3,2,1,5,
					1,-1,2,1,3,
					0,2,3,-1,4);
			System.out.print(m3);
			System.out.println("Determinante: " + m3.determinant() + "\n");
			
			//trasposta di m3
			System.out.println("Test SquareMatrix trasposta: ");
			System.out.print("Originale:\n" + m3);
			SquareMatrix m3t = m3.transposed();
			System.out.println("Trasposta:\n" + m3t);
			
			// 3 operazioni elementari
			
			SquareMatrix m5r = m3;
			System.out.println("Test operazioni elementari:");
			System.out.print("\nOriginale:\n" + m5r);
			m5r.swapRows(0, 2);
			System.out.print("\nScambio prima e terza riga:\n" + m5r);
			
			SquareMatrix m5c = m3;
			System.out.print("\nOriginale:\n" + m5c);
			m5c.swapCols(0, 2);
			System.out.print("\nScambio prima e terza colonna:\n" + m5c);
			
			SquareMatrix mswap = m3;
			mswap.substituteRow(0, 2, 0.5);
			System.out.println("\nScambio prima con il doppio della terza:\n" + mswap);
			
			System.out.println("\nTest matrice diagonale");
			SquareMatrix m8 = new SquareMatrix(3,
					1, 0, 0,
					0, 4, 0,
					0, 0, 2);
			System.out.print(m8);
			
			if (m8.isDiagonal())
				System.out.println("La matrice è diagonale\n");
			
			//matrice identità
			System.out.println("Test matrice identità:");
			SquareMatrix m5 = SquareMatrix.identityMatrix(5);
			System.out.println(m5);
			
			//matrice di zeri
			System.out.println("Test matrice di zeri:");
			SquareMatrix m6 = SquareMatrix.zeroMatrix(5);
			System.out.println(m6);
			
			System.out.println("------------------");
			System.out.println("| MATRICE SPARSA |");
			System.out.println("------------------");
			System.out.println();
			
			//matrice sparsa
			System.out.println("Test matrice sparsa:");
			SparseMatrix m7 = new SparseMatrix(4, 4,
					0, 0, 1, 0,
					0, 2, 0, 0,
					0, 0, 3, 2,
					0, 0, 0, 4);
			System.out.print(m7);
			System.out.println("Sparsità: " + m7.getSparsity());
			System.out.println("La matrice è densa? " + (m7.isDense() ? "Vero" : "Falso"));
			
		}
		catch(RuntimeException exc) {
			System.err.println(exc.getClass().getName() + " -> " + exc.getMessage());
		}
	}
}
