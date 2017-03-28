# Setup Google Test

Project properties for use Google Test:

## C/C++

### Code Generation

#### Configuration: Debug, Platform: All Platforms

	Runtime Library: Multi-threaded Debug (/MTd)
	
#### Configuration: Release, Platform: All Platforms

	Runtime Library: Multi-threaded (/MT)
	
### General

#### Configuration: All Configurations, Platform: All Platforms

	Additional Include Directories: D:\CPP\Libraries\gTest\1.7\googletest\include;%(AdditionalIncludeDirectories)
	
## Linker

### General
	
#### Configuration: All Configurations, Platform: All Platforms

	Additional Library Directories: D:\CPP\Libraries\gTest\1.7\googletest\stage\msvc14\$(Platform)\$(Configuration);%(AdditionalLibraryDirectories)
	
### Input	
	
#### Configuration: All Configurations, Platform: All Platforms

	gtest.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies)
