#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>

namespace File_utils {

	void concatenate(const std::string &ifname1, const std::string &ifname2, const std::string &ofname);

	void concatenate_self(const std::string &ifname, const std::string &ofname);

	void concatenate_overwrite(const std::string &iofname1, const std::string &ifname2);

	void concatenate_self_overwrite(const std::string &iofname);

	/*
	 * Opens the file for reading in binary mode.
	 * Also sets the stream to throw exception on ios_base::badbit.
	 */
	void open_read(const std::string &fname, std::ifstream &ist);

	/*
	 * Opens the file for writing in binary mode.
	 * Also sets the stream to throw exception on ios_base::badbit.
	 */
	void open_write(const std::string &fname, std::ofstream &ost, bool append = false);

	void open_rw(const std::string &fname, std::fstream &iost);

	/*
	 * Reads from ist into ost.
	 */
	void read_into(std::ifstream &ist, std::ofstream &ost);

}

#endif
