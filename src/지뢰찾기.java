public class 지뢰찾기 {
    public static void main(String[] args) {

        //명령행 인수 m,n,p 받고 m * n 배열 생성
        int m = Integer.parseInt(args[0]);
        int n = Integer.parseInt(args[1]);
        double p = Double.parseDouble(args[2]);

        String[][] ary = new String[m][n];

        //지뢰 랜덤 생성 => 확률p에 의해서
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Math.random() < 0.3) {
                    ary[i][j] = "*";
                } else {
                    ary[i][j] = "-";
                }
            }
        }

        //배열 출력을 통해 지뢰 위치 확인
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(ary[i][j]);
            }
            System.out.println();
        }

        //근처 지뢰 개수를 가시화
        for (int i = 0; i < m; i++) { //(0,0) (1,0) ... (m-1,0)

            for (int j = 0; j < n; j++) { //(0,0) (0,1) .... (0,n-1)
                int count = 0; //근처의 지뢰 개수
                if (ary[i][j].equals("*")) { //지뢰가 있다면 지뢰를 출력
                    System.out.print("*");
                }

                else { //지뢰가 없다면 기준으로 8방향에 몇개의 지뢰가 있는지 개수 출력
                    if ((i == 0)) { //가장 윗쪽
                        if (j == 0) { //왼쪽 윗 꼭지점
                            if (ary[i][j + 1].equals("*") ) {
                                count++;
                            }
                            if(ary[i + 1][j + 1].equals("*")){
                                count++;
                            }
                            if(ary[i + 1][j].equals("*")){
                                count++;
                            }
                        } else if (j == n - 1) { //오른쪽 위 꼭지점
                                if(ary[i][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j-1].equals("*")){
                                    count++;
                                }
                                if(ary[i+1][j].equals("*")){
                                   count++;
                                }
                        } else { //나머지 가장 윗쪽 사이드
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
                    } else if (j == n-1) { //가장 오른쪽 사이드
                        if (i == m-1) { //오른쪽 밑 꼭지점
                            if(ary[i][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j-1].equals("*")){
                                count++;
                            }
                            if(ary[i-1][j].equals("*")){
                                count++;
                            }
                        } else { //나머지 오른쪽 사이드
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
                    } else if (j == 0) { //가장 왼쪽 사이드
                        if(i == m-1){ //왼쪽 아래 꼭지점
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
                        else{ //나머지 왼쪽 사이드
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
                    } else if (i == m-1) { //가장 아래 사이드
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
