# Sherlan200k
**SHERLAN** stands for:
- **S**ubword
- **H**ybrid
- **E**ncode
- **R**epresentation
- **L**anguage
- **A**nalysis
- **N**etwork

**200k** refers to the target vocabulary size of 200,000 tokens.

## Overview
Sherlan200k is a hybrid tokenization framework designed to produce a comprehensive vocabulary of 200,000 tokens. This project combines the strengths of BPE (Byte Pair Encoding) and SentencePiece tokenization methods, leveraging diverse corpora, including Stack Overflow and general English datasets, to achieve a more efficient representation of language. 

This project is still under development. Contributions and feedback are welcome!

## Features
- **Hybrid Tokenization**: Combines BPE and SentencePiece for better token coverage and semantic understanding.
- **Large Vocabulary**: Aims to produce a vocabulary size of 200,000 tokens, allowing for finer granularity in text representation.
- **Corpora Diversity**: Utilizes multiple text sources to ensure a rich and varied tokenization process.
## Installation
To use Sherlan200k, clone the repository and install the required dependencies.
```bash
git clone https://github.com/yourusername/sherlan200k.git
cd sherlan200k
pip install -r requirements.txt
```

## Technical highlights
- **Training the Tokkenizer**:To train the SentencePiece tokenizer on your text files, run:
```
python train.py
```
- This will generate the tokenization models for the specified datasets.
- **Encoding and Decoding**:You can use the following methods to encode and decode text using the trained models
```
from hybrid_tokenizer import HybridTokenizer

tokenizer = HybridTokenizer("models/spm_model_stackoverflow.model", "models/spm_model_general.model")
tokens = tokenizer.encode("Your text here")
decoded_text = tokenizer.decode(tokens)
```
## Development Status

This project is still under development. The following features are planned for future releases:

* Enhanced model merging strategies
* Improved performance metrics
* Additional corpus integration


## Contributing
Contributions are welcome! If you would like to contribute to the Sherlan200k project, please fork the repository and submit a pull request.


## License
This project is licensed under the MIT License. See the LICENSE file for details.


## Acknowledgments
* [SentencePiece](https://github.com/google/sentencepiece) for tokenization.
* [BPE](https://github.com/first20hours/google-10000-english) for initial vocabulary strategies.
* Stack Overflow and various English datasets for corpus contribution.

## Citation
If you use Sherlan200k in your research or projects, please cite it as follows:
```
Arjun.S.Nair.@2024. Sherlan200k: A hybrid tokenization framework. Retrieved from https://github.com/Ajwebdevs/sherlan200k
```
## Update Logs
Updates coming soon....