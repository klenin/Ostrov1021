1. Установить python (anaconda)  
https://www.anaconda.com/download/  
Во время установки поставить галочку добавить в переменную path  

2. Установка tensorflow  
Для повышения производительности лучше устанавливать tensorflow с поддержкой GPU.  
Список поддерживаемых видеокарт https://developer.nvidia.com/cuda-gpus  
Для установки tensorflow с поддержкой GPU требуется:  
    1.Microsoft Visual Studio (https://visualstudio.microsoft.com)  
    Требуется не старее Visual Studio 2013.  
    Далее для корректной установки програмного обеспечения требуется английская версия интерфейса в Visual Studio.  

    В случае если язык интефейса не английский следует сделать следующее:  

        1.Откройте установку и удаление программ и выберите Visual Studio

        2.Нажмите кнопку "Изменить"

        3.Выберите вкладку "Языковой пакет" в левом верхнем углу

        4.Проверьте нужный язык и нажмите кнопку "Изменить" внизу справа

    2.Установить CUDA Toolkit версии 9.0 (https://developer.nvidia.com/cuda-toolkit-archive)  
    ВНИМАНИЕ TensorFlow не поддерживает более новые версии CUDA  

    3.Установить cuDNN  (https://developer.nvidia.com/rdp/form/cudnn-download-survey)  
    cuDNN следует распаковать в директорию где установлена CUDA.  
    Обычно (C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v9.0)  

    4.pip install --upgrade tensorflow-gpu  
 
Установка tensorflow без поддержки GPU:  
    1.pip install --upgrade tensorflow  
 
Проверка установки tensorflow для python:
```python
    import tensorflow as tf  
    hello = tf.constant('Hello, TensorFlow!')  
    sess = tf.Session()  
    print(sess.run(hello))  
```

3. Установка Caffe  
http://caffe.berkeleyvision.org/installation.html  

4. Scikit-learn  
pip install -U scikit-learn  