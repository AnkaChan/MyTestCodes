#ifndef _AC_IO_H_
#define _AC_IO_H_

#include "def.h"
#include "io.h"
namespace AC {
	struct IO
	{
		struct FileParts
		{
			std::string path;
			std::string name;
			std::string ext;
		};
		static FileParts fileparts(std::string filename)
		{
			std::replace(filename.begin(), filename.end(), '\\', '/'); // replace all '\' to '/', fuck Microsophtte

			int idx0 = filename.rfind("/");

			int idx1 = filename.rfind(".");

			FileParts fp;
			fp.path = filename.substr(0, idx0 + 1);
			fp.name = filename.substr(idx0 + 1, idx1 - idx0 - 1);
			if (idx1 != -1) {
				fp.ext = filename.substr(idx1);
			}
			else
			{
				fp.ext = "";
			}

			return fp;
		}

		static void getJustCurrentFile(std::string path, VecStr& files) {
			//文件句柄
			long long hFile = 0;
			//文件信息
			struct _finddata_t fileinfo;
			std::string p;
			if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
				do {
					if ((fileinfo.attrib & _A_SUBDIR)) {
						;
					}
					else {
						files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					}
				} while (_findnext(hFile, &fileinfo) == 0);
				_findclose(hFile);
			}
		}

		/************************************************************************/
		/*  获取文件夹下所有文件名
		输入：
		path    :   文件夹路径
		exd     :   所要获取的文件名后缀，如jpg、png等；如果希望获取所有
		文件名, exd = ""
		输出：
		files   :   获取的文件名列表
		HolaMirai 2016/11/24 添加保存文件名到.txt文件中
		shao, 20140707
		*/
		/************************************************************************/
		static void getFilesWithExt(std::string path, std::string exd, VecStr& files)
		{
			//文件句柄
			long long  hFile = 0;
			//文件信息
			struct _finddata_t fileinfo;
			std::string pathName, exdName;

			if (0 != strcmp(exd.c_str(), ""))
			{
				exdName = "\\*." + exd;
			}
			else
			{
				exdName = "\\*";
			}

			if ((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(), &fileinfo)) != -1)
			{
				do
				{
					//如果是文件夹中仍有文件夹,迭代之
					//如果不是,加入列表
					// 不推荐使用，硬要使用的话，需要修改else 里面的语句
					/*if((fileinfo.attrib &  _A_SUBDIR))
					{
					if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );
					}
					else */
					{
						if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							files.push_back(pathName.assign(path).append("\\").append(fileinfo.name)); // 要得到绝对目录使用该语句
																									   //如果使用
																									   //files.push_back(fileinfo.name); // 只要得到文件名字使用该语句
					}
				} while (_findnext(hFile, &fileinfo) == 0);
				_findclose(hFile);
			}
		}
	};

	
}

#endif