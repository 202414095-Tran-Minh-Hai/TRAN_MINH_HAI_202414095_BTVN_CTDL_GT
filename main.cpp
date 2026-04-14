// em chào cô ạ   
#include <iostream>;
using namespace std;
// mô tả số hạng
struct sohang {
	float heso;
	int somu;
	sohang* next;
};
// hàm tạo ra số hạng mới
sohang* taosohang(float a, int b) {
	sohang* sohangmoi = new sohang;
	sohangmoi->heso = a;
	sohangmoi->somu = b;
	sohangmoi->next = nullptr;
	return sohangmoi;
}

// hàm thêm số hạng vào đa thức thứ tự mũ giảm dần
void themsohang(sohang*& head, float a, int b) {
	if (a == 0) return; // he so = 0 khoong them
	sohang* sohangmoi = taosohang(a, b); // tạo ra chuỗi số hạng chứa các hệ số và số mũ 
	// chèn vào đâu danh sách
	if (head == nullptr || b > head->somu) {
		sohangmoi->next = head;
		head = sohangmoi;
	}
	
	// chèn giữa
	else {
		sohang* hientai = head;
		while (hientai->next != nullptr && hientai->next->somu >= b) {
			hientai = hientai->next;
		}

		// mux bằng thì cộng hệ số
		if (hientai->somu == b) {
			hientai->heso += a;
			delete sohangmoi; // xóa vì số hạng mới đã cộng vào số hạng hiện tại

		}
		else {
			sohangmoi->next = hientai->next;
			hientai->next = sohangmoi;
		}
	}
}