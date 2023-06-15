
# <b> Elevating Website Security: Generating and Deploying a Self-Signed SSL Certificate with HashiCorp's Vault and NGINX </b>

Welcome to the comprehensive guide on using HashiCorp's Vault and NGINX to host a website on your local host with a self-signed certificate. This tutorial will walk you through the entire process of securely managing secrets with HashiCorp's Vault while setting up NGINX as a web server to host your website. By utilizing a self-signed certificate, we will establish a secure HTTPS connection for your local website, ensuring encrypted communication between the client and the server.

Throughout this guide, we will cover all the necessary steps, including generating a self-signed certificate for your local host, configuring NGINX to utilize HTTPS, importing the certificate into HashiCorp's Vault for secure storage, retrieving the certificate from Vault, and finally, hosting the website using NGINX with the self-signed certificate. By following these instructions, you will gain valuable insights into securely managing secrets, setting up a web server, and securing your website with a self-signed certificate.

Whether you are a developer testing a website locally, setting up a development environment, or simply exploring the process of managing secrets and deploying secure websites, this guide will provide you with the knowledge and practical steps to accomplish your goal. So, let's get started and dive into the exciting world of using HashiCorp's Vault and NGINX to host a website on your local host with a self-signed certificate!

#





## **Quick navigations**

<br>
<br>

## [Pre-requisite knowledge](/9c8225d5-167f-a741-155a-c8db9033eb6d)

<br>
<br>
<br>

#

<br>






## <p> **Section 1: Pre-requisite knowledge** </p>

<br>



<p>

## <p> **1.1** Data handling across the internet and SSL Certificates </p>

#

#### <p> <b> What asymmetric keys and how are they used to handle data across the internet? </b> </p>

<p>

Asymmetric keys, also known as public-key cryptography, are cryptographic keys that come in pairs: a public key and a private key. This form of encryption is widely used across the internet to secure data transmission, ensure confidentiality, integrity, and authenticity of communication.
Here's how asymmetric keys are used to handle data across the internet:
- Key Generation: The process begins by generating a pair of asymmetric keys. The private key is kept secret by the owner, while the corresponding public key is shared with others.
- Encryption: To send encrypted data, the sender uses the recipient's public key to encrypt the message. This ensures that only the intended recipient, who possesses the corresponding private key, can decrypt and access the original message.
- Decryption: Upon receiving the encrypted message, the recipient uses their private key to decrypt it and retrieve the original content. Since the private key is kept secret, only the recipient can perform this decryption operation.
- Digital Signatures: Asymmetric keys are also used for digital signatures, which provide data integrity and authentication. To sign a message, the sender uses their private key to create a unique digital signature, which is then appended to the message. The recipient can verify the authenticity of the message by using the sender's public key to validate the digital signature.
- Authentication and Key Exchange: Asymmetric keys are used in protocols like Transport Layer Security (TLS) to establish secure connections between clients and servers. During the TLS handshake, the server presents its public key to the client, which is then used for encrypting the session key. The client encrypts the session key with the server's public key, ensuring only the server can decrypt it with the corresponding private key. This shared session key is then used for symmetric encryption, which is more efficient for bulk data transmission.
Asymmetric key encryption is computationally intensive compared to symmetric key encryption, so it is often used in combination with symmetric encryption. The asymmetric keys are primarily used for securely exchanging symmetric keys, while the symmetric keys handle the actual encryption and decryption of the data.

</p>

<br>

#### <p> **What is an SSL Certificate?** </p>

<p>

An SSL certificate, also known as a Secure Sockets Layer certificate, is a digital certificate that provides authentication and encryption for secure communication over the internet. SSL certificates are used to establish secure connections between web servers and clients, ensuring that data transmitted between them remains confidential and protected from unauthorized access.

Here are some key aspects of SSL certificates:
- Encryption: SSL certificates facilitate encryption of data during transmission. When a website has an SSL certificate installed, the communication between the web server and the client's browser is encrypted, making it difficult for unauthorized individuals to intercept and understand the transmitted data. This encryption helps protect sensitive information, such as login credentials, credit card details, and personal data.
- Authentication: SSL certificates provide authentication, assuring visitors that they are communicating with the intended website and not an imposter or a malicious entity. The certificate verifies the identity of the website and associates it with a cryptographic key pair. This authentication is achieved through the trusted Certificate Authorities (CAs) that issue SSL certificates after verifying the ownership and legitimacy of the website.
- Trust Indicators: Websites with SSL certificates display trust indicators to visitors, such as a padlock icon in the browser's address bar, the "https://" protocol prefix, or a green address bar in some cases. These indicators signal that the website has implemented SSL encryption and that the connection is secure. They instill confidence in visitors, reassuring them that their data is protected during their interaction with the website.
- Types of SSL Certificates: SSL certificates come in different types, such as domain-validated (DV), organization-validated (OV), and extended validation (EV) certificates. The level of validation and information displayed in the certificate varies among these types. EV certificates, for example, involve a rigorous validation process and display the organization's name prominently in the browser's address bar, providing an enhanced level of trust to users.
- Certificate Authorities (CAs): SSL certificates are issued by trusted Certificate Authorities, which are organizations that have been authorized to validate and issue certificates. Web browsers and operating systems maintain a list of trusted CAs, and if a website's SSL certificate is signed by one of these trusted CAs, it is considered valid and trusted by the browser.

SSL certificates play a vital role in securing online transactions, protecting sensitive data, and establishing trust between websites and visitors. They are an essential component of modern web security and are widely used to ensure secure communication on websites, e-commerce platforms, email servers, and other online services.

</p>

<br>

#### <p> **When it comes to identity, what issue does asymmetric encryption hold and how does the use of certificates handle this problem?** </p>

<p>

One problem that arises is the issue of trust and verifying the authenticity of an entity's identity in the digital realm. The use of certificates helps address this problem by providing a trusted means of verifying the identity of individuals, organizations, or devices.
The main problem with identity in the digital world is that anyone can claim to be someone or something they are not. This creates a challenge when trying to establish trust and ensure that you are communicating with the intended party. For example, when accessing a website, you want to be certain that you are connecting to the legitimate website and not an imposter trying to steal your information.
This is where certificates come into play. Certificates are digital documents issued by trusted third-party entities known as Certificate Authorities (CAs). These certificates bind an entity's identity (such as a website or an individual) to a cryptographic key pair (consisting of a public key and a private key).

Certificates work in the following way to handle the problem of identity:
- Certificate Issuance: The entity seeking a certificate generates a key pair and creates a Certificate Signing Request (CSR) containing their public key and identity information. The CSR is then sent to a trusted CA.
- Identity Verification: The CA verifies the identity of the entity through various validation processes. This can involve checking domain ownership, verifying legal documents, or conducting background checks for individuals.
- Certificate Signing: If the CA is satisfied with the identity verification, they digitally sign the CSR using their private key. This creates a digital certificate that binds the entity's identity to their public key.
- Certificate Distribution: The CA provides the signed certificate back to the entity. The certificate contains information about the entity's identity, the public key, and the CA's digital signature.
- Certificate Validation: When the entity presents its certificate to other parties (such as website visitors), the certificate is checked for validity. This involves verifying the CA's digital signature using the CA's public key, ensuring the certificate has not expired, and checking for any revocation status.

By using certificates, the problem of identity is addressed in the following ways:
1. Trust: Certificates are issued by trusted CAs, which are organizations that have established their credibility and integrity. By relying on these trusted authorities, users can have confidence in the authenticity of the identities presented in certificates.
2. Authentication: Certificates provide a way to authenticate the identity of an entity. The CA's digital signature on the certificate assures the recipient that the public key presented by the entity indeed belongs to the claimed identity.
3. Non-Repudiation: Certificates support non-repudiation, which means that the entity cannot deny their association with the certificate. The digital signature from the CA provides a proof of the entity's identity, preventing them from disowning their actions or communications.

Certificates play a crucial role in addressing the problem of identity in the digital world by providing trusted means of verifying identities. They establish trust, authenticate entities, and enable non-repudiation, enhancing security and enabling secure communication across various online platforms.

</p>

<br>

####  <p> **Who are these issuing authorities and why will I trust them?** </p>

<p>

The issuing authorities of SSL certificates, also known as Certificate Authorities (CAs), are trusted organizations responsible for verifying the identity and authenticity of entities requesting SSL certificates. These CAs play a crucial role in establishing trust in the digital certificate ecosystem.

Here's how trust in Certificate Authorities is established:
- Trusted Root CAs: Web browsers and operating systems maintain a list of pre-installed trusted root CAs. These root CAs are considered inherently trusted, as they have undergone rigorous vetting and auditing processes to ensure their reliability and security. Examples of well-known root CAs include Digicert, Symantec, GlobalSign, Let's Encrypt, and Comodo.
- Certification Authorities/Browser Forum: The Certification Authorities/Browser (CA/B) Forum is an industry consortium that sets standards and guidelines for CAs and browser vendors. The forum defines policies and practices that CAs must follow to maintain trust. These include requirements for certificate issuance, validation procedures, and security measures.
- Certificate Issuance Process: CAs follow specific processes to issue SSL certificates. They verify the ownership and control of the domain or organization requesting the certificate. This process typically involves verifying domain registration records, conducting email or phone verification, or validating legal documentation for organizations. The CAs must adhere to the validation guidelines established by the CA/B Forum to ensure consistent and reliable certificate issuance.
- Auditing and Compliance: CAs undergo regular audits and assessments to validate their compliance with industry standards and best practices. These audits verify that CAs are following the prescribed procedures, maintaining security controls, and protecting their private key infrastructure. Audit reports, such as WebTrust or ETSI standards, provide evidence of the CA's compliance.
- Certificate Revocation: In cases where a CA has issued a compromised or fraudulent certificate, or if a certificate needs to be revoked for any reason, CAs maintain Certificate Revocation Lists (CRLs) or use Online Certificate Status Protocol (OCSP) to indicate the revoked status of certificates. Web browsers and other relying parties regularly check the revocation status of certificates to ensure their validity.
- Browser and Operating System Trust: Web browsers and operating systems trust the root CAs by including their root certificates in their default trust stores. This trust is based on the rigorous vetting and auditing processes that the root CAs have undergone. Browsers and operating systems periodically update their trust stores to add or remove CAs based on their adherence to standards and practices.

> It's important to note that while CAs play a critical role in establishing trust, they are not infallible. There have been instances where CAs have issued certificates erroneously or under fraudulent circumstances. However, the industry has mechanisms in place to detect and address such incidents, such as browser blacklisting of compromised certificates and public scrutiny.

Trust in Certificate Authorities is established through the inclusion of their root certificates in trusted browser and operating system stores, adherence to industry standards and audits, validation processes, and the ability to revoke compromised certificates. These measures collectively help ensure the integrity and reliability of SSL certificates and maintain trust in the digital certificate ecosystem.

</p>

<br>

#### <p> **Can I be my own Certifying Authority?** </p>

<p>

Yes, it is possible to become your own Certifying Authority (CA) and issue your own digital certificates. This is known as setting up a private CA. However, it's important to note that the certificates issued by a private CA will not be automatically trusted by web browsers and operating systems, as they are preconfigured to trust specific root CAs.

Here are the basic steps involved in setting up your own private CA:
- Generate a Root Certificate: The first step is to generate a self-signed root certificate. This certificate will act as the root of trust for your private CA. You can use tools like OpenSSL to generate the root certificate.
- Establish Certificate Policies and Procedures: Define the policies and procedures for your private CA, including the validation processes, certificate issuance guidelines, and security measures. This helps ensure consistency and security in the certificate issuance process.
- Set up Certificate Authority Infrastructure: Create the infrastructure for your private CA, which typically includes a secure server or hardware module to store and protect the private key associated with the root certificate. This infrastructure is critical for maintaining the security and integrity of your private CA.
- Issue and Manage Certificates: With your private CA infrastructure in place, you can start issuing digital certificates. These certificates can be used for various purposes such as securing web servers, email communication, or internal systems. You will need to follow your defined policies and procedures for verifying identities and issuing certificates.
- Distribute and Install Trust: Since your private CA is not pre-trusted by default, you would need to manually distribute and install the root certificate of your private CA to the clients or systems that need to trust your certificates. This ensures that they recognize and trust your private CA as a valid authority.

> It's important to understand that while you can set up your own private CA, the certificates issued by it will only be trusted within the specific systems or environments where you have distributed and installed the root certificate. They will not be automatically recognized as trusted by web browsers or other systems unless you go through a process of getting your root certificate included in their trust stores.
> Setting up and managing a private CA requires careful consideration of security practices, infrastructure, and trust establishment. It is typically more suitable for internal use within organizations or closed systems rather than for publicly trusted certificates used on the internet.

<p>

<br>

#### <p> **What are the benefits in me being my own CA?** </p>

<p>

Being your own Certifying Authority (CA) offers several benefits:

- Flexibility and Control: As your own CA, you have complete control over the issuance and management of digital certificates. You can tailor the certificate issuance process to meet your specific needs and define your own policies and procedures. This level of flexibility allows you to adapt the CA operations to the unique requirements of your organization or environment.
- Cost Savings: By operating your own CA, you eliminate the need to rely on third-party commercial CAs for obtaining certificates. This can result in significant cost savings, especially if you require a large number of certificates or have long-term certificate needs.
- Rapid Certificate Issuance: With your own CA, you can issue certificates quickly without having to wait for approval or validation from external CAs. This is particularly beneficial in fast-paced environments where certificates need to be provisioned rapidly to support new services, systems, or development workflows.
- Enhanced Security: Being your own CA allows you to enforce strong security measures throughout the certificate lifecycle. You have control over the security of the private keys associated with the CA, ensuring they are stored and managed in a highly secure manner. This reduces the risk of private key compromise and unauthorized certificate issuance.
- Custom Trust: By distributing and installing your CA's root certificate within your organization or specific systems, you establish a custom trust model. This means that the certificates issued by your CA will be automatically trusted within your defined trust boundaries. It provides a higher level of assurance and control over the trustworthiness of the certificates used within your environment.
- Internal PKI: Running your own CA enables the establishment of an internal Public Key Infrastructure (PKI) within your organization. This allows you to issue and manage certificates for internal services, systems, and users. It facilitates secure communication, authentication, and data protection within your organization's infrastructure.
- Isolation and Privacy: By having your own CA, you can ensure that your organization's certificates and cryptographic operations remain isolated from external entities. This helps maintain the privacy and confidentiality of your internal communications and prevents the reliance on external CAs that may have access to your certificate issuance activities.

> You're also required to note that operating your own CA also comes with responsibilities, such as implementing strong security practices, ensuring proper certificate management, and maintaining the integrity of the CA infrastructure. However, the benefits of being your own CA can outweigh these considerations, particularly for organizations that require greater control, customization, and cost efficiency in managing their digital certificates.

</p>

<br>
<br>

</p>



<p>

## <p> **1.2** Structure and working of HashiCorp's Vault </p>

#

#### <p> **What is HashiCorp's Vault?** </p>

<p>

HashiCorp's Vault is an open-source software tool designed for securely managing and storing sensitive data, such as passwords, API keys, cryptographic keys, and other secrets. It provides a centralized solution for managing secrets across different applications and infrastructure.

Key features and concepts of HashiCorp Vault include:
- Secret Management: Vault allows you to securely store and manage secrets in a central repository. Secrets can be stored, accessed, and revoked programmatically or via a user-friendly interface. Vault supports various secret types, including key-value pairs, certificates, database credentials, and dynamic secrets.
- Encryption and Access Control: Vault encrypts and protects secrets at rest using encryption algorithms and employs access control mechanisms to enforce fine-grained access policies. Access to secrets is controlled through authentication methods, which can include username/password, tokens, certificates, or integration with external identity providers.
- Dynamic Secrets: Vault can generate dynamic secrets on-demand for various systems and services. These dynamic secrets have short-lived lifetimes, reducing the risk of compromised credentials. Examples include generating dynamic database credentials, cloud service tokens, or SSH keys.
- Secret Rotation: Vault provides mechanisms for securely rotating secrets, such as automatically generating new credentials and securely distributing them to applications. This helps mitigate the risks associated with long-lived or static credentials.
- Auditing and Monitoring: Vault logs and audits all access and operations, providing visibility into who accessed which secrets and when. This audit trail helps meet compliance requirements and facilitates troubleshooting and forensic analysis.
- Integration and Extensibility: Vault integrates with various authentication providers, including Active Directory, LDAP, AWS IAM, and GitHub. It can also integrate with external systems for key management and secrets retrieval. Additionally, Vault offers an API and a plugin architecture that allows extending its capabilities and integrating with other tools and workflows.
- High Availability and Scalability: Vault supports high availability deployments to ensure the availability of secrets even in the event of failures. It can be deployed in a clustered configuration for scalability and fault tolerance, enabling the handling of large-scale deployments and demanding workloads.

Vault is widely used in cloud-native and DevOps environments, where securing and managing secrets is crucial. It helps organizations improve security, simplify secrets management, and adhere to security best practices by providing a secure and scalable solution for secret storage and access control.

</p>

<br>

#### <p> **The Structure and Workign of HashiCorp's Vault** </p>

<p>

HashiCorp's Vault is a highly flexible and secure secrets management tool that helps organizations store, manage, and distribute sensitive data, such as passwords, API keys, encryption keys, and certificates. Vault operates based on a client-server architecture, where the Vault server manages the secure storage and retrieval of secrets, while clients interact with the server to access and manage those secrets.

Here's an overview of the structure and working of HashiCorp's Vault:
- Vault Server: The Vault server is the core component responsible for storing and managing secrets. It securely stores secrets in an encrypted format and provides access control mechanisms to ensure that only authorized users or systems can access the stored secrets. The server can be deployed in a high-availability configuration to ensure reliability and fault tolerance.
- Authentication and Authorization: Vault supports various authentication methods to verify the identity of clients. Users or systems must authenticate themselves before accessing the stored secrets. Vault integrates with external authentication providers like LDAP, Active Directory, and cloud identity services. After authentication, Vault enforces access control policies to determine the level of authorization for each client.
- Secrets Engine: Vault incorporates different secrets engines to handle various types of secrets. Secrets engines are modules responsible for generating, storing, and managing secrets. Examples of secrets engines include the Key/Value secrets engine for storing key-value pairs, Database secrets engine for dynamically generating database credentials, and PKI secrets engine for managing certificates and private keys.
- Encryption and Data Protection: Vault employs encryption to protect secrets at rest and in transit. The secrets are encrypted using strong cryptographic algorithms, and Vault manages the encryption keys securely. This ensures that even if the underlying storage or network is compromised, the secrets remain protected.
- Dynamic Secrets: Vault introduces the concept of dynamic secrets, which are secrets generated on-demand for specific systems or applications. Dynamic secrets have a limited lifespan, reducing the risk of compromised credentials. For example, Vault can generate dynamic database credentials that expire after a specified period, enhancing security.
- Secret Lifecycle Management: Vault provides mechanisms for securely rotating and revoking secrets. It supports secret rotation, where new secrets are generated and distributed while the old ones are revoked. This helps mitigate the risks associated with long-lived or compromised secrets. Vault also tracks secret metadata and enables auditing of secret access and usage.
- Auditing and Logging: Vault logs and audits all access and operations performed by clients. It maintains an audit trail of actions, including who accessed which secrets and when. This audit trail is crucial for compliance purposes, as well as for monitoring and investigating security incidents.
- Integration and Extensibility: Vault offers an extensive API and a plugin architecture that enables integration with other tools, systems, and workflows. It supports integration with external key management systems, cloud providers, identity providers, and orchestration platforms. This extensibility allows Vault to be seamlessly integrated into existing environments and workflows.

HashiCorp's Vault provides a secure and scalable solution for managing secrets, ensuring that sensitive data remains protected throughout its lifecycle. Its flexible architecture, support for multiple authentication methods, secrets engines, and auditing capabilities make it a valuable tool for organizations seeking robust secrets management and data protection.

</p>

<br>

#### <p> **How does HashiCorp's Vault help me in becoming my own Certifying Authority?** </p>

<p>

Becoming your own Certifying Authority (CA) involves setting up your own infrastructure to issue and manage digital certificates. While HashiCorp's Vault is not specifically designed to function as a CA, it can play a role in securely managing the private keys and secrets associated with operating a CA.

While Vault is not specifically designed to function as a CA, it can assist in securely managing the private keys and secrets associated with operating a CA. Here's how Vault can contribute to the CA process:
1. Secret Management: Vault can securely store and manage the private keys associated with your CA, ensuring they are protected and accessible only to authorized users or systems.
2. Key Protection: Vault provides cryptographic key management features, including secure key storage, access controls, and key rotation mechanisms. These features help protect the private keys used for signing certificates and ensure their confidentiality and integrity.
3. Secrets Encryption: Vault can encrypt and store sensitive data, such as CA root certificates, intermediate certificates, and other secrets associated with the CA infrastructure. This ensures that the sensitive information remains secure and confidential.
4. Access Control: Vault offers robust access control mechanisms to manage who can access and manage the CA's secrets. It supports various authentication methods and fine-grained access policies, enabling you to control and restrict access to the CA's secrets based on user roles and permissions.
5. Auditability and Compliance: Vault provides auditing and logging capabilities, allowing you to track and monitor access to the CA secrets. This audit trail helps meet compliance requirements and facilitates security monitoring and forensic analysis.

> While Vault does not provide the core functionality of a CA, it can serve as a secure and centralized secrets management platform to safeguard the critical components of a CA infrastructure, such as private keys, certificates, and other sensitive data.

</p>

<br>
<br>

</p>



<p>

## <p> **1.3** NGINX and its services </p>

#

#### <p> **What is NGINX?** </p>

<p>

NGINX (pronounced "engine X") is a popular open-source web server and reverse proxy server known for its high performance, scalability, and robustness. Originally created to solve the C10k problem (handling a large number of concurrent connections), NGINX has gained significant popularity and is widely used as a web server, load balancer, reverse proxy, and caching server.

Here are some key features and functionalities of NGINX:
- Web Server: NGINX can serve static and dynamic web content, handling HTTP and HTTPS requests. It efficiently processes incoming requests and serves responses to clients, making it suitable for hosting websites and web applications.
- Reverse Proxy: NGINX acts as an intermediary between clients and backend servers, forwarding client requests to the appropriate servers and relaying responses back to the clients. It helps distribute incoming traffic across multiple backend servers, improving performance, scalability, and availability.
- Load Balancer: NGINX can balance the load across multiple backend servers by intelligently distributing incoming requests based on various algorithms such as round-robin, least connections, IP hash, and more. This helps distribute the workload evenly and improves the overall performance and resilience of the system.
- Caching: NGINX can cache static and dynamic content, reducing the load on backend servers and improving response times for subsequent requests. It can cache responses based on configurable rules, such as URL patterns or HTTP headers, effectively serving cached content to clients, eliminating the need for repeated processing.
- SSL/TLS Termination: NGINX can handle SSL/TLS encryption and decryption, acting as a termination point for secure connections. It offloads the computational overhead of SSL/TLS encryption from backend servers, improving their performance and simplifying the management of SSL/TLS certificates.
- Security and Access Control: NGINX provides various security features and options to protect web applications, including access control based on IP addresses, rate limiting to mitigate DoS attacks, and request filtering to block malicious requests. It offers granular control over request handling and can be integrated with additional security tools and modules.
- High Performance and Scalability: NGINX is known for its high-performance architecture, optimized for handling a large number of concurrent connections and delivering content quickly. It efficiently utilizes system resources, making it suitable for high-traffic websites and applications.
- Flexible Configuration: NGINX uses a declarative configuration syntax that is highly flexible and allows customization of server behavior. It supports advanced configuration options, including rewrite rules, header manipulation, URL redirection, and more, providing fine-grained control over how requests are handled.

NGINX is widely adopted by organizations of all sizes, from small businesses to large enterprises, as well as by popular websites and web applications. Its combination of performance, scalability, flexibility, and extensive feature set makes it a powerful tool for serving web content, load balancing, and enhancing the overall performance and security of web applications.

</p>

<br>

#### <p> **How will NGINX be of use to us?** </p>

<p>

We will utilize NGINX as the web server to host our website. NGINX is a high-performance web server known for its efficiency, scalability, and robustness. By leveraging NGINX, we can ensure that our website is delivered to users with optimal speed and reliability.
With NGINX as our web server, we can handle a large number of concurrent connections and efficiently serve static and dynamic content. This means that our website will be able to handle high volumes of traffic without compromising performance.

NGINX supports SSL/TLS encryption, allowing us to secure our website with HTTPS. It can handle the SSL/TLS termination process, relieving our backend server from the computational overhead. This ensures that the communication between our website and users is encrypted and secure.

NGINX's flexibility and extensive configuration options enable us to set up URL rewriting and redirection, improving the user experience and search engine optimization of our website. We can easily define rules to redirect or rewrite URLs, ensuring that users can access our content through clean and user-friendly URLs.

</p>

</p>

</p>

<br>
<br>
<br>

#

<br>





## <p> **Section 2: Utilising HashiCorp's Vault services to become your own Certifying Authority** </p>

<br>



<p>

## <p> **2.1** Installing and Initializing HashiCorp's Vault </p>

#

<p>

For our purpose, we will be using a Linux based Operating System; Ubuntu in our case. Kindly follow the below steps to install and initialize your Vault.

<br>

#### <p> **Step 1: Installing HashiCorp's Vault** </p>

<p>

Open a new terminal and execute the follwing command to install Vault.

``` ~$ sudo apt-get install vault ```

This command will install Vault in your Ubuntu system.

</p>

<p>

Upon successful installation, you will be able to view Vault's 'help' menu by executing the following command.

``` ~$ vault ```

</p>

<br>

#### <p> **Step 2: Initializing the Vault** </p>

<p>

We'll start by initializing the server. Run the below command to start the server in 'dev' mode. The 'dev' mode simply a pre-unsealed vault that has already been configure to meet the basic requirement.

``` ~$ vault server -dev ```

> Kindly note that you must never start the Vault in 'dev' mode during production. This mode must only be used for demonstration and testing purposes.

</p>

<p>

Now that we've initialized the Vault, we'll be presented with the localhost address the server has been hosted in and the token required to access the Vault server.

> Keep in mind that this token must not be shared with others. As this wil act as a 'password' to access our Vault, anyone with this token will be able to access your Vault, which may void the purpose of a vault.

In out case, our vault server has been hosted in the address `http://127.0.0.1:8200`. Surfing your browser with address will lead you to the landing page of your Vault, we're you'll be queried with your token.

With this, you will have successfully initiated your Vault and logged in and the homepage you're presented with would look something like this.

<br>

![Alt text](<VAULT homepage.png>)

</p>

</p>

<br>
<br>

<p>

## <p> <b> 2.2 </b> Setting up the root Certifying Authority </p>

</p>

#

<p>

The root Certifying Authority (CA), also known as the root certificate authority, is the highest level of authority in a public key infrastructure (PKI) system. It is the entity that issues and signs the root certificate, which is the foundation of trust for all other certificates within the PKI.

The root CA is responsible for establishing trust by digitally signing and issuing certificates for intermediate CAs and end-entity certificates. It acts as the ultimate source of trust in the certificate chain. Root certificates are typically self-signed, meaning they are signed with their own private key, and their public key is distributed and trusted by operating systems, web browsers, and other certificate validation mechanisms.
The inclusion of a root certificate in a trusted store is what allows the certificates issued by that root CA to be trusted. Root certificates are pre-installed in operating systems and web browsers and are used to verify the authenticity and integrity of certificates presented by websites, services, or entities in the PKI ecosystem.

> It's important to note that the private key of a root CA should be securely stored and protected since compromising the root CA's private key would undermine the entire PKI system's security and trust.

Root CAs are typically operated by trusted organizations, such as commercial CAs, government entities, or large enterprises. The trustworthiness of a root CA is established through a thorough validation process, adherence to industry standards and best practices, and regular audits or assessments to ensure the integrity of their operations.

<br>
<br>

#### <p> **Step 1: Enabling PKI Certificates in a directory** </p>

<p>

1. Under the *Secrets* tab, start by navigating into the *Enable new engine* option. You will find yourself in this menu:
<br>
<br>
    ![Alt text](<Enable new engine.png>)

    In this menu, click on 'Next' after selecting `PKI Certificates` under the 'Generic' section.
<br>
<br>

</p>

<p>

2. Now you'll have to select a path inwhich you'd like to access your root Certificate Authority from. By default it is set to 'pki'. However, we may change it according to our convenience. In our case, we'll be going with 'Root' as our path.

    ![Alt text](<Enable Root path.png>)
<br>
<br>
Under *Method Options* enable `Max Lease TTL`. Now you may set the maximum duration your root may issue a certificate with. In our case, we'll go with `87600 hours` (10 years).
<br>
<br>
![Alt text](<Root MTTL.png>)
<br>
Ater choosing your maximum TTL, click on `Enable Engine` to enable your PKI engine.

</p>

<br>

#### <p> **Step 2: Configuring your root CA** </p>

<p>

1. Within this directory you just created, under the *Configuration* tab, click on `Configure`. Then, proceed by clicking on `Configure CA`. Here, make sure the 'CA Type' is set as *root*. Now, enter a common name. This will be your domain. For our purpose, we'll use `domain.com` as our domain. Upon deployment, it is extremely recommended to enter your address as well. Upon following all the instruction, your page should look somewhat like this.

    ![Alt text](<Root configure CA.png>)

    Exit by clicking on `Save`.
<br>
<br>

</p>

<p>

2. What has been generated is your certificate. You may save this certificate in `.crt ` or `.pem ` format. We'll be saving it as `rootCA.pem`. Copy the certificate and save it with a name of your choicewith one of the given extensions.
<br>
<br>

</p>

<p>

3. After saving it, switch over to the *URLs* tab. Paste the following under the respective fields.
    
    - Issuing certificates:

        `<IP_ADDRESS_VAULT_IS_HOSTED_IN>:<PORT_NUMBER>/v1/<DIRECTORY_OF_ROOT_CA>/ca`

        In our case, it'll be `http://127.0.0.1:8200/v1/Root/ca`
    
    - CRL Distribution Points:

        `<IP_ADDRESS_VAULT_IS_HOSTED_IN>:<PORT_NUMBER>/v1/<DIRECTORY_OF_ROOT_CA>/crl`

        In our case, it'll be `http://127.0.0.1:8200/v1/Root/crl`
    
    Save it before proceeding to the next step.
    
</p>

<br>

#### <p> **Step 3: Issuing a certificate for a sub-domain directly from the root CA (Not recommended)** </p>

<p>

1. From the *Secrets* tab, go to the directory you have your root CA configured in.

    ![Alt text](<Root create role option.png>)

    Under the *Roles* tab, click on `Create role` to create a new role.

    - Now, assign a name to it. We'll go with `rootRole`.

    - Under the `Hide Domain Handling` drop down, enable `Allow subdomains` and add your domain (`domain.com` in our case) in the text box provided under the title *Allowed domains*.

    - Now at the top write of the webpage, there will be an option to open a console. Click on this option and execute the command below.

    ```read -field=default <DIRECTORY_OF_ROOT>/config/issuers```

    In our case, it'll be `read -field=default Root/config/issuers`. Copy the ID you receive and paste it under the *Issuer ref* field.

    - Under the *Show options*, you'll find an option to set the Max TTL. This is nothing but the maximum duration of certificate the role can issue. Note that this will take input in seconds; which means you'll have to convert your duration to seconds before setting up the value. Leave it blank will allow it to take the default duration as the Max TTL, which is the Max TTL you set up for the corresponding authority the role is created in.
    - Proceed by clicking on *Create role*.
    <br>
    <br>

</p>

<p>

2. From the *Roles* tab, click on the role you just created. In this menu, you'll be able to issue certificates for your subdomains.

    - Enter the subdomain you would liek to issue the certificate for. We'll be going with `root.domain.com`.

    - Select `pem_bundle` as the format.

    - Under *Options* enter the duration of the certificate i.e. the lease period. When the period you entered exceed the max duration that can be alotted by the role, you'll be issued with that maximum duration as the lease period of your certificate. We'll set our period as `720 hours` (30 days).

    Here's what your panel would look like.

    ![Alt text](<Root certificate details.png>)

    Proceed by generating your certificate.

    What we see here are the details of the certificate you just issued for your subdomain. Click on `Copy credentials` and save it in any readable format. You'll be copying all this details in the form of a `.json ` file so whichever format you choose, as long as you can read it, you may use it. We'll not be using this anywhere as an entirel file. It only holds the credentials that you may need later.

    Now what interests us are the following fields:

    - **Certificate:** This is your public key. You'll be needing this later on in this guide. Copy this key and save it as a `.crt ` file. We'll be saving it as `rootPublic.crt`.

    > While saving this file, if you find yourself having more than 1 section, the second section is what the public key is. You may remove the rest. 

    - **Private key:** This is the private key you'll be using later on as a pair with your public key. Copy this key and save it as a `.key` file. We'll be saving it as `rootPrivate.key`.

    - **CA chain:** You will need this for uploading it in your browser later on. This is the certificate your browser will use to ensure that your domain is secure. Save it as a `.pem ` file. We'll be savin it as `rootAuthority.pem`.

    > Make sure to copy everything including the '----------CERTIFICATE----------` part.

</p>

</p>




</p>