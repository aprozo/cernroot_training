FROM rootproject/root:6.28.00-ubuntu22.04

# # Run the following commands as super user (root):
# USER root

RUN apt-get update && apt-get install -y git python3-pip

RUN python3 -m pip install --upgrade wheel jupyter metakernel dask distributed pyspark

# # Create a user that does not have root privileges 
# ARG username=physicist
# RUN useradd --create-home --home-dir /home/${username} ${username}
# ENV HOME /home/${username}

# WORKDIR /home/${username}

# # Create the configuration file for jupyter and set owner
# RUN echo "c.NotebookApp.ip = '*'" > jupyter_notebook_config.py && chown ${username} *

# # Switch to our newly created user
# USER ${username}

# # Allow incoming connections on port 8888
# EXPOSE 8888

# # Start ROOT with the --notebook flag to fire up the container
# CMD ["root", "--notebook"]
