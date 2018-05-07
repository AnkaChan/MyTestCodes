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
			//�ļ����
			long long hFile = 0;
			//�ļ���Ϣ
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
		/*  ��ȡ�ļ����������ļ���
		���룺
		path    :   �ļ���·��
		exd     :   ��Ҫ��ȡ���ļ�����׺����jpg��png�ȣ����ϣ����ȡ����
		�ļ���, exd = ""
		�����
		files   :   ��ȡ���ļ����б�
		HolaMirai 2016/11/24 ��ӱ����ļ�����.txt�ļ���
		shao, 20140707
		*/
		/************************************************************************/
		static void getFilesWithExt(std::string path, std::string exd, VecStr& files)
		{
			//�ļ����
			long long  hFile = 0;
			//�ļ���Ϣ
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
					//������ļ����������ļ���,����֮
					//�������,�����б�
					// ���Ƽ�ʹ�ã�ӲҪʹ�õĻ�����Ҫ�޸�else ��������
					/*if((fileinfo.attrib &  _A_SUBDIR))
					{
					if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					getFiles( pathName.assign(path).append("\\").append(fileinfo.name), exd, files );
					}
					else */
					{
						if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							files.push_back(pathName.assign(path).append("\\").append(fileinfo.name)); // Ҫ�õ�����Ŀ¼ʹ�ø����
																									   //���ʹ��
																									   //files.push_back(fileinfo.name); // ֻҪ�õ��ļ�����ʹ�ø����
					}
				} while (_findnext(hFile, &fileinfo) == 0);
				_findclose(hFile);
			}
		}
	};

	
}

#endif