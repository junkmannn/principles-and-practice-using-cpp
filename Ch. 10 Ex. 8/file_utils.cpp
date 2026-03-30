#include <fstream>
#include "file_utils.h"

using namespace std;

namespace File_utils {

	void concatenate(const std::string &ifname1, const std::string &ifname2, const std::string &ofname) {
		ifstream ist1;
		open_read(ifname1, ist1);

		ifstream ist2;
		open_read(ifname2, ist2);

		ofstream ost;
		open_write(ofname, ost);

		read_into(ist1, ost);
		read_into(ist2, ost);
	}

	void concatenate_self(const std::string &ifname, const std::string &ofname) {
		ifstream ist;
		open_read(ifname, ist);

		ofstream ost;
		open_write(ofname, ost);

		read_into(ist, ost);
		ist.clear();
		ist.seekg(0, ist.beg);
		read_into(ist, ost);
	}

	void concatenate_overwrite(const std::string &iofname1, const std::string &ifname2) {
		ofstream ost;
		open_write(iofname1, ost, true);

		ifstream ist;
		open_read(ifname2, ist);

		read_into(ist, ost);
	}

	void concatenate_self_overwrite(const std::string &iofname) {
		fstream iost;
		open_rw(iofname, iost);

		// get file size
		iost.seekg(0, ios::end);
		int file_size = iost.tellg();
		iost.seekg(0, ios::beg);

		// init buffer
		int buf_size = 16384;
		char *buf = new char[buf_size];

		int batches = file_size / buf_size;
		int leftover = file_size % buf_size;

		int pos = 0; // cursor position
		for (int i = 0; i < batches; ++i) {
			pos = i * buf_size;
			iost.seekg(pos);
			iost.read(buf, buf_size);
			iost.seekp(pos + file_size);
			iost.write(buf, buf_size);
		}

		pos = batches * buf_size;
		iost.seekg(pos);
		iost.read(buf, leftover);
		iost.seekp(pos + file_size);
		iost.write(buf, leftover);

		delete[] buf;
	}

	void open_read(const std::string &fname, std::ifstream &ist) {
		ist.open(fname, ios::in | ios::binary);
		if (!ist) throw runtime_error("Could not open " + fname + " for reading.");
		ist.exceptions(ist.exceptions() | ios_base::badbit);
	}

	void open_write(const std::string &fname, std::ofstream &ost, bool append) {
		ost.open(fname, ios::out | ios::binary | (append ? ios::app : 0));
		if (!ost) throw runtime_error("Could not open " + fname + " for writing.");
		ost.exceptions(ost.exceptions() | ios_base::badbit);
	}

	void open_rw(const std::string &fname, std::fstream &iost) {
		iost.open(fname, ios::in | ios::out | ios::binary);
		if (!iost) throw runtime_error("Could not open " + fname + " for reading/writing.");
		iost.exceptions(iost.exceptions() | ios_base::badbit);
	}

	void read_into(std::ifstream &ist, std::ofstream &ost) {
		int buf_size = 16384;
		char *buf = new char[buf_size];
		int bytes_read = 0;

		do {
			ist.read(buf, buf_size);
			bytes_read = ist.gcount();
			ost.write(buf, bytes_read);
		} while (bytes_read == buf_size);

		delete[] buf;
	}

}
