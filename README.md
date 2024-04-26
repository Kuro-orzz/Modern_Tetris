# Modern tetris
## Giới thiệu bản thân
- Họ và tên: Đỗ Tuấn Hưng
- Lớp: K68-J
- Mã sinh viên: 23020674
- Bài tập lớn INT2215_52 Lập trình nâng cao

## Giới thiệu game
- Đây là một tựa game phản xạ, sử dụng 7 khối block S, Z, L, J, I, T, O để xếp vào trong 1 bảng với kích thước 20x10. 

## Video trải nghiệm game và trình bày qua về code
- Link youtube: https://www.youtube.com/watch?v=_4dlSFNPW5k

- [0. Cách tải game](#0-cách-tải-game)
- [1. Bắt đầu game](#1bắt-đầu-game)
- [2. Tính năng:](#2-tính-năng)
- [3. Cách chơi](#3-cách-chơi)
- [Về đồ họa của game:](#về-đồ-họa-của-game)
- [Về source code game](#về-source-code-game)



# 0. Cách tải game

**Bước 1:** 
- Clone repo này về hoặc Chọn Code -> Download Zip
- Tất cả code đều nằm trong thư mục src
- Có thể nhảy đến bước 5 để chơi luôn.

**Bước 2:** Cài mingw. Ở đây tôi cài đặt phiên bản MinGW-W64 GCC-8.1.0 [x86_64-posix-seh]
Một số chú ý:

- Nếu sử dụng trình biên dịch khác thì phải dịch lại icon: vào thư mục icon rồi dùng
  lệnh `windres main.rc -O coff main.res` trong cmd.<br/>
- Phải xóa ba dll của c++ trong thư mục chứa pvz.exe: `libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll`. Ba
  dll này chỉ dành cho người chơi không cài sẵn c++ trong máy.

**Bước 3:** Cài GNU make

**Bước 4:** Mở cmd trong thư mục chứa Makefile và gõ lệnh make.

**Bước 5:** Bật Unimare.exe và chơi

# 1. Bắt đầu game
Chạy vào bảng chọn menu có các lựa chọn cho mình

-`Play` : Bắt đầu game mới từ level 0.<br/>
-`Level` ![]() : Chọn level từ  đến 20 với mức độ rơi từ chậm đến nhanh của các khối block.<br/>
-`High score` ![](): Trong đây sẽ lưu những điểm số cao nhất mà mọi người đạt được khi chơi<br/>
-`Quit` ![]() : để thoát khỏi game.<br/>
![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Tetris_v3/img_src/menu.png)

# 2. Tính năng

- Cách tính random các block không hoàn toàn ngẫu nhiên mà có quy luật, cứ hiện hết 7 block các loại thì mới có khả năng hiện các block trùng loại. Nó giúp cho game cân bằng hơn khi không random lệch block nhiều, block ít, mà giúp tần suất các block xuất hiện là tương đương nhau
- Khi bắt đầu một màn chơi mới, chúng ta có thể dễ dàng thấy được phần hold ở phía góc trên bên trái của bảng, tác dụng của nó là giúp ta giữ lại được 1 khối block để sau này có thể dùng khi cần thiết hoặc giúp ta giữ lại block hiện tại vì block đó tạo nên hình xếp không đẹp trong bảng.
- Còn 1 chức năng nữa là next piece, nó cho phép chúng ta thấy trước được 5 piece tiếp theo ở trong bảng

![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Review_game/Game.png)

- Game sẽ có level từ 0 đến 20, mỗi level sẽ có tốc độ rơi tăng dần, nếu muốn từ level này qua level tiếp theo thì chúng ta cần phải phá số hàng là số level+5.

![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Review_game/choose_level.png)

- Trong quá trình chơi game sẽ có 1 nút ấn bên trái, nếu ấn vào đó nó sẽ hiện lên các lựa chọn, chúng ta có thể lựa chọn chơi tiếp hoặc chơi lại level đó, hoặc chọn quay về menu 

![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Tetris_v3/img_src/resume.png)

- Khi mà các khối block bị xếp cao lên đến đỉnh thì chúng ta sẽ thua và màn hình sẽ hiện lên điểm của chúng ta trong ván chơi đó.

![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Review_game/score.png)

- Nếu điểm chúng ta đủ lớn thì có thể sẽ xuất hiện ở trong mục high score, nơi ghi lại top 5 điểm cao nhất.

![image](https://github.com/Kuro-orzz/Modern_Tetris/blob/main/Review_game/high_score.png)

# 4.	 Cách chơi

- Dùng các phím mũi tên trái, phải để di chuyển sang trái và phải sao cho block vẫn nằm trong bảng, nếu block chạm cạnh bảng thì sẽ dừng lại, không di chuyển được tiếp sang bên đó nữa.
- Dùng phím mũi tên xuống để block rơi nhanh hơn hoặc space để block đột ngột thả xuống dưới cho đến khi va chạm với block khác.
- Dùng mũi tên lên hoặc phím x để xoay block theo chiều kim đồng hồ, dùng phím z để block xoay ngược chiều kim đồng hồ
- Dùng phím c để sử dụng chắc năng hold.
  
### Về đồ họa của game:
- Thao khảo từ Lazyfoo để biết thêm các hàm vẽ lên màn hình và các hàm trong sdl nói chung
- Về phần hình ảnh em có lấy từ các nguồn như Plant zoombie và serach trên google
