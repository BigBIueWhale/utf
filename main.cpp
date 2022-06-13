#include <string>
#include <string_view>

// 0xxxxxxx
// 110zzzzz 10yyyyyy
// 1110xxxx 10yyyyyy 10zzzzzz
// 11110www 10zzzzzz 10yyyyyy 10xxxxx

extern std::u32string utf8_to_utf32(const std::u8string_view utf8_str);
extern std::u8string utf32_to_utf8(const std::u32string_view utf32_str);

#include <iostream>
#include <array>

bool are_utf_conversions_valid(const std::u8string_view original) {
	const std::u32string utf32_str = utf8_to_utf32(original);
	const std::u8string utf8_str = utf32_to_utf8(utf32_str);
	return utf8_str == original;
}

#include <array>

extern constinit const std::array<std::u8string_view, 25> valid_utf8_strings;

int main() {
	for (const auto& str : valid_utf8_strings) {
		if (!are_utf_conversions_valid(str)) {
			std::cout << "Invalid UTF-8 string: " << std::endl;
			return 1;
		}
	}
	std::cout << "All UTF-8 strings are valid." << std::endl;
	return 0;
}

constinit const std::array<std::u8string_view, 25> valid_utf8_strings{
	{
		u8"שלום לכם",
		u8"你好",
		u8"こんにちは",
		u8"안녕하세요",
		u8"Привет",
		u8"\xD7\xA1\xD7\xA2\xD7\xA3\xD7\xA4\xD7\xA5\xD7\xA6\xD7\xA7\xD7\xA8\xD7\xA9\xD7\xAA\xD7\xAB\xD7\xAC\xD7\xAD\xD7\xAE\xD7\xAF",
		u8"\xD7\xB0\xD7\xB1\xD7\xB2\xD7\xB3\xD7\xB4\xD7\xB5\xD7\xB6\xD7\xB7\xD7\xB8\xD7\xB9\xD7\xBA\xD7\xBB\xD7\xBC\xD7\xBD\xD7\xBE\xD7\xBF",
		u8"\xD7\xC0\xD7\xC1\xD7\xC2\xD7\xC3\xD7\xC4\xD7\xC5\xD7\xC6\xD7\xC7\xD7\xC8\xD7\xC9\xD7\xCA\xD7\xCB\xD7\xCC\xD7\xCD\xD7\xCE\xD7\xCF",
		u8"\xD7\xD0\xD7\xD1\xD7\xD2\xD7\xD3\xD7\xD4\xD7\xD5\xD7\xD6\xD7\xD7\xD8\xD7\xD9\xD7\xDA\xD7\xDB\xD7\xDC\xD7\xDD\xD7\xDE\xD7\xDF",
		u8"\xD7\xE0\xD7\xE1\xD7\xE2\xD7\xE3\xD7\xE4\xD7\xE5\xD7\xE6\xD7\xE7\xD7\xE8\xD7\xE9\xD7\xEA\xD7\xEB\xD7\xEC\xD7\xED\xD7\xEE\xD7\xEF",
		u8"\xD7\xF0\xD7\xF1\xD7\xF2\xD7\xF3\xD7\xF4\xD7\xF5\xD7\xF6\xD7\xF7\xD7\xF8\xD7\xF9\xD7\xFA\xD7\xFB\xD7\xFC\xD7\xFD\xD7\xFE\xD7\xFF",
		u8"\xD8\x00\xD8\x01\xD8\x02\xD8\x03\xD8\x04\xD8\x05\xD8\x06\xD8\x07\xD8\x08\xD8\x09\xD8\x0A\xD8\x0B\xD8\x0C\xD8\x0D\xD8\x0E\xD8\x0F",
		u8"\xD8\x10\xD8\x11\xD8\x12\xD8\x13\xD8\x14\xD8\x15\xD8\x16\xD8\x17\xD8\x18\xD8\x19\xD8\x1A\xD8\x1B\xD8\x1C\xD8\x1D\xD8\x1E\xD8\x1F",
		u8"\xD8\x20\xD8\x21\xD8\x22\xD8\x23\xD8\x24\xD8\x25\xD8\x26\xD8\x27\xD8\x28\xD8\x29\xD8\x2A\xD8\x2B\xD8\x2C\xD8\x2D\xD8\x2E\xD8\x2F",
		u8"\xD8\x30\xD8\x31\xD8\x32\xD8\x33\xD8\x34\xD8\x35\xD8\x36\xD8\x37\xD8\x38\xD8\x39\xD8\x3A\xD8\x3B\xD8\x3C\xD8\x3D\xD8\x3E\xD8\x3F",
		u8"\xD8\x40\xD8\x41\xD8\x42\xD8\x43\xD8\x44\xD8\x45\xD8\x46\xD8\x47\xD8\x48\xD8\x49\xD8\x4A\xD8\x4B\xD8\x4C\xD8\x4D\xD8\x4E\xD8\x4F",
		u8"\xD8\x50\xD8\x51\xD8\x52\xD8\x53\xD8\x54\xD8\x55\xD8\x56\xD8\x57\xD8\x58\xD8\x59\xD8\x5A\xD8\x5B\xD8\x5C\xD8\x5D\xD8\x5E\xD8\x5F",
		u8"\xD8\x60\xD8\x61\xD8\x62\xD8\x63\xD8\x64\xD8\x65\xD8\x66\xD8\x67\xD8\x68\xD8\x69\xD8\x6A\xD8\x6B\xD8\x6C\xD8\x6D\xD8\x6E\xD8\x6F",
		u8"\xD8\x70\xD8\x71\xD8\x72\xD8\x73\xD8\x74\xD8\x75\xD8\x76\xD8\x77\xD8\x78\xD8\x79\xD8\x7A\xD8\x7B\xD8\x7C\xD8\x7D\xD8\x7E\xD8\x7F",
		u8"\xD8\x80\xD8\x81\xD8\x82\xD8\x83\xD8\x84\xD8\x85\xD8\x86\xD8\x87\xD8\x88\xD8\x89\xD8\x8A\xD8\x8B\xD8\x8C\xD8\x8D\xD8\x8E\xD8\x8F",
		u8"\xD8\x90\xD8\x91\xD8\x92\xD8\x93\xD8\x94\xD8\x95\xD8\x96\xD8\x97\xD8\x98\xD8\x99\xD8\x9A\xD8\x9B\xD8\x9C\xD8\x9D\xD8\x9E\xD8\x9F",
		u8"\xD8\xA0\xD8\xA1\xD8\xA2\xD8\xA3\xD8\xA4\xD8\xA5\xD8\xA6\xD8\xA7\xD8\xA8\xD8\xA9\xD8\xAA\xD8\xAB\xD8\xAC\xD8\xAD\xD8\xAE\xD8\xAF",
		u8"\xD8\xB0\xD8\xB1\xD8\xB2\xD8\xB3\xD8\xB4\xD8\xB5\xD8\xB6\xD8\xB7\xD8\xB8\xD8\xB9\xD8\xBA\xD8\xBB\xD8\xBC\xD8\xBD\xD8\xBE\xD8\xBF",
		u8"\xD8\xC0\xD8\xC1\xD8\xC2\xD8\xC3\xD8\xC4\xD8\xC5\xD8\xC6\xD8\xC7\xD8\xC8\xD8\xC9\xD8\xCA\xD8\xCB\xD8\xCC\xD8\xCD\xD8\xCE\xD8\xCF",
		u8"\xD8\xD0\xD8\xD1\xD8\xD2\xD8\xD3\xD8\xD4\xD8\xD5\xD8\xD6\xD8\xD7\xD8\xD8\xD8\xD9\xD8\xDA\xD8\xDB\xD8\xDC\xD8\xDD\xD8\xDE\xD8\xDF"
	}
};

#include <bit>
#include <sstream>
#include <stdexcept>

std::u32string utf8_to_utf32(const std::u8string_view utf8_str) {
	const auto get_utf8_sequence_size_from_first_char =
		[](const char8_t ch) -> int
	{
		const int num_of_1s = std::countl_one(std::uint8_t{ ch });
		int sequence_size{};
		if (num_of_1s == 0) {
			sequence_size = 1;
		}
		else if (num_of_1s >= 2 && num_of_1s <= 4) {
			sequence_size = num_of_1s;
		}
		else {
			std::ostringstream err_msg;
			err_msg << "Invalid UTF-8 sequence."
					<< " Starting character in sequence: " << int{ ch }
					<< " num_of_1s: " << num_of_1s;
			throw std::runtime_error(err_msg.str());
		}
		return sequence_size;
	};
	const auto is_valid_2nd_3rd_4th_char = [](const char8_t ch) -> bool
	{
		// Verify that the character is in the correct place in the sequence
		const int num_of_1s = std::countl_one(std::uint8_t{ ch });
		return num_of_1s == 1;
	};
	std::u32string utf32_str{};
	int count_chars_in_current_sequence_so_far = 0;
	int expected_num_chars_in_sequence = 0;
	std::uint_fast32_t current_sequence_bits = 0;
	
	const auto push_byte = [&current_sequence_bits, &count_chars_in_current_sequence_so_far](const char8_t c) -> void
	{
		const int num_bits_unused = std::countl_one(std::uint8_t{ c }) + 1;
		const int num_bits_used = 8 - num_bits_unused;
		current_sequence_bits <<= num_bits_used;
		current_sequence_bits |= static_cast<std::uint_fast32_t>(
			static_cast<std::uint8_t>(c << num_bits_unused) >> num_bits_unused
			);
		++count_chars_in_current_sequence_so_far;
	};

	for (const char8_t c : utf8_str) {
		if (count_chars_in_current_sequence_so_far == 0) {
			expected_num_chars_in_sequence = get_utf8_sequence_size_from_first_char(c);
		}
		else {
			if (!is_valid_2nd_3rd_4th_char(c)) {
				std::ostringstream err_msg;
				err_msg << "Invalid UTF-8 sequence."
						<< " Invalid 2nd, 3rd or 4th char " << int{ c }
					    << " required to have 1 leading 1, instead observed"
						<< " num_of_1s: " << std::countl_one(std::uint8_t{ c });
				throw std::runtime_error{ err_msg.str() };
			}
		}
		push_byte(c);
		
		if (count_chars_in_current_sequence_so_far == expected_num_chars_in_sequence) {
			const auto utf32_char = static_cast<std::uint32_t>(current_sequence_bits);
			current_sequence_bits = 0;
			count_chars_in_current_sequence_so_far = 0;
			expected_num_chars_in_sequence = 0;
			utf32_str.push_back(char32_t{ utf32_char });
		}
	}

	return utf32_str;
}

std::u8string utf32_to_utf8(const std::u32string_view utf32_str) {
	std::u8string utf8_str;
	static constexpr int max_num_bits_in_utf8_character = 21;
	for (const char32_t utf32_char : utf32_str) {
		if (utf32_char <= 0x7F) {
			utf8_str.push_back(static_cast<char8_t>(utf32_char));
		}
		else if (utf32_char <= 0x7FF) {
			utf8_str.push_back(static_cast<char8_t>(0xC0 | (utf32_char >> 6)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | (utf32_char & 0x3F)));
		}
		else if (utf32_char <= 0xFFFF) {
			utf8_str.push_back(static_cast<char8_t>(0xE0 | (utf32_char >> 12)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | ((utf32_char >> 6) & 0x3F)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | (utf32_char & 0x3F)));
		}
		else if (utf32_char <= 0x10FFFF) {
			utf8_str.push_back(static_cast<char8_t>(0xF0 | (utf32_char >> 18)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | ((utf32_char >> 12) & 0x3F)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | ((utf32_char >> 6) & 0x3F)));
			utf8_str.push_back(static_cast<char8_t>(0x80 | (utf32_char & 0x3F)));
		}
		else {
			std::ostringstream err_msg;
			err_msg << "Invalid UTF-32 character: " << int64_t{ utf32_char };
			throw std::runtime_error{ err_msg.str() };
		}
	}
	return utf8_str;
}
