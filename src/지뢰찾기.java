public class ����ã�� {
    public static void main(String[] args) {

        //����� �μ� m,n,p �ް� m * n �迭 ����
        int m = Integer.parseInt(args[0]);
        int n = Integer.parseInt(args[1]);
        double p = Double.parseDouble(args[2]);

        String[][] ary = new String[m][n];

        //���� ���� ���� => Ȯ��p�� ���ؼ�
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Math.random() < 0.3) {
                    ary[i][j] = "*";
                } else {
                    ary[i][j] = "-";
                }
            }
        }

        //�迭 ����� ���� ���� ��ġ Ȯ��
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(ary[i][j]);
            }
            System.out.println();
        }

        //��ó ���� ������ ����ȭ
        for (int i = 0; i < m; i++) { //(0,0) (1,0) ... (m-1,0)

            for (int j = 0; j < n; j++) { //(0,0) (0,1) .... (0,n-1)
                int count = 0; //��ó�� ���� ����
                if (ary[i][j].equals("*")) { //���ڰ� �ִٸ� ���ڸ� ���
                    System.out.print("*");
                }

                else { //���ڰ� ���ٸ� �������� 8���⿡ ��� ���ڰ� �ִ��� ���� ���
                    if ((i == 0)) { //���� ����
                        if (j == 0) { //���� �� ������
                            if (ary[i][j + 1].equals("*") ) {
                                count++;
                            }
                            if(ary[i + 1][j + 1].equals("*")){
                                count++;
                            }
                            if(ary[i + 1][j].equals("*")){
                                count++;
                            }
                        } else if (j == n - 1) { //������ �� ������
                                if(ary[i][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j].equals("*")){
                                   count++;
                                }
                        } else { //������ ���� ���� ���̵�
                                if(ary[i][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j + 1].equals("*")){
                                    count++;
                                }
                                if(ary[i][j+1].equals("*")){
                                    count++;
                                }
                        }
                    } else if (j == n-1) { //���� ������ ���̵�
                        if (i == m-1) { //������ �� ������
                            if(ary[i][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                        } else { //������ ������ ���̵�
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                            if(ary[i - 1][j - 1].equals("*")){
                                count++;
                            }
                            if(ary[i][j - 1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j - 1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j].equals("*")){
                                count++;
                            }
                        }
                    } else if (j == 0) { //���� ���� ���̵�
                        if(i == m-1){ //���� �Ʒ� ������
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i][j+1].equals("*")){
                                count++;
                            }
                        }
                        else{ //������ ���� ���̵�
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j].equals("*")){
                                count++;
                            }
                        }
                    } else if (i == m-1) { //���� �Ʒ� ���̵�
                        if(ary[i][j-1].equals("*")){
                            count++;
                        }
                        if(ary[i-1][j-1].equals("*")){
                            count++;
                        }
                        if(ary[i-1][j].equals("*")){
                            count++;
                        }
                        if(ary[i-1][j+1].equals("*")){
                            count++;
                        }
                        if(ary[i][j+1].equals("*")){
                            count++;
                        }
                    } else{
                            if(ary[i-1][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j].equals("*")){
                                count++;
                            }
                            if(ary[i+1][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j+1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                    }
                    System.out.print(count);
                }
            }
            System.out.println();
        }

    }
}
