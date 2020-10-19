import setuptools


with open('Document.md', encoding='utf-8') as f:
    long_description = f.read()

setuptools.setup(
    name='pkce',
    version='1.0',
    author='Kuldeep Chhipa',
    author_email='kuldeepchhipa9991@gmail.com',
    description='PKCE Pyhton generator.',
    long_description=long_description,
    long_description_content_type="text/markdown",
    url='https://github.com/Kuldeep-Chhipa/pkce',
    packages=['pkce'],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3',
)
